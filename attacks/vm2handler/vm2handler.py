#!/usr/bin/python3
"""
This script will receive:
    target - a script to run inside the ps (process selector)
  folder
    region - one of heap|stack|vdso|vvar

And return the related page address

The return is the mfn on the current context. 
BEWARE:  if running on a VM environment this can not
necessearly mean the real physical address.

"""

import argparse
import os
import random
import struct
import logging
import subprocess
import traceback

from utils.bash_utils import run_cmd, execute_or_abort
from utils.log_util import ScriptLogger

logger = None  # type: logging.Logger

DEBUG = False


def get_host_information(host: str) -> dict:
    # try ssh to validate
    h = {}
    h["hostname"] = run_cmd("ssh {} hostname".format(host))
    h["id"] = run_cmd("xl list {} | grep {} | awk '{{print $2}}'".format(host, host))
    return h


def hex_string(in_str):
    if in_str and len(in_str) < 2:
        raise argparse.ArgumentTypeError("It should have at least one byte specifying not {}".format(len(in_str)))
    
    hexs = in_str.split()
    if len(hexs) < 1:
        raise argparse.ArgumentTypeError("At least one byte should be specified".format(len(in_str)))

    for h in hexs:
        try:
            if int(h,16) > 255:
                raise argparse.ArgumentTypeError("Illegal by specifier {}".format(h))
        except ValueError:
            raise argparse.ArgumentTypeError("Illegal by specifier {}".format(h))
    
    return in_str

if __name__ == '__main__':

    if os.geteuid() != 0:
        exit("You need to have root privileges to run this script.\n"
             "Please try again, this time using 'sudo'. Exiting.")

    parser = argparse.ArgumentParser(
        description='Script to get a physical page address (in the current context)'
                    'given a process selector script and a specification\n'
                    'Must be root to run this p')
    parser.add_argument('--host', '-H', metavar='host', type=str, required=True,
                        help='Host where the script will get the pages.')
    parser.add_argument('--region', '-r', metavar='memory_regions', type=str, choices=('stack', 'heap', 'vdso', 'vvar', 'exec'),
                        required=True, help='Area from possible addresses to obtain, one of: %(choices)s', )
    parser.add_argument('--action', '-a', metavar='action', type=str, choices=('write','find'),
                        required=True, help='Action to take in the page, one of: %(choices)s', )
    parser.add_argument('--order', '-o', metavar='page-order', required=True, type=str, choices=('first', 'last', 'random','all'),
                        default='first',
                        help='The order of the page to return, one of: %(choices)s')
    parser.add_argument('--hex', '-x', type=hex_string, required=True,
                        help='Value to use in the action is needed. Must be a sequence of bytes encoded as \
                        hexadecimal separeted by space: Ex. "EB FA 14 F5"')
    parser.add_argument('--script', '-s', metavar='script', type=str, required=True, help='Script under the ps folder')
    parser.add_argument('--debug', '-d', action='store_true', required=False, default=False,
                        help='Enable printing debug messages')
    parser.add_argument('--quiet', '-q', action='store_true', required=False, default=False,
                        help='Print additional information')

    args = parser.parse_args()

    DEBUG = args.debug

    # Validate all values

    # Start Script
    script_logger = ScriptLogger(__file__, debug=DEBUG, mute_console=args.quiet)
    logger = script_logger.get_main_logger()

    logger.debug("Starting vm2handler with: {}".format(args))

    logger.info("Collect host information {}".format(args.host))
    try:
        host = get_host_information(args.host)
        logger.info("Host information {}".format(host))
    except subprocess.CalledProcessError as e:
        logger.error("The host Specified is not valid\n:{}".format(e))
        logger.error("\n\tError Output:\n{}\n".format(e.output))
        logger.error("!! {}".format(traceback.format_exc()))
        exit(1)

    logger.info("Get GPFN from target host")
    cmd = "ssh {} 'cd vm2handler && python3 domU_broker.py --script {} --region {} " \
          "--order {}'".format(host["hostname"], args.script, args.region, args.order)

    gpfn = execute_or_abort(cmd, "Could not acquire the gpfn", log=logger)
    logger.info("Returned GPFN {}".format(gpfn))

    cmd = "cd dom0 && ./page_exploiter -d {} -a {} -H '{}' {}".format(host["id"], args.action, args.hex, gpfn)
    output = execute_or_abort(cmd, "Could not exploit page",cmd_msg="Will exploit the page with",log=logger)

    logger.info("Output of the page exploiter: \n{}\n".format(output))
    logger.info("Exploit done!!")

