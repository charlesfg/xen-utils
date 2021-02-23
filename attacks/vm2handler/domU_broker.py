#!/usr/bin/python
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

from utils.bash_utils import run_cmd
from utils.log_util import ScriptLogger

logger = None  # type: logging.Logger

DEBUG = False

if __name__ == '__main__':

    if os.geteuid() != 0:
        exit("You need to have root privileges to run this script.\n"
             "Please try again, this time using 'sudo'. Exiting.")

    parser = argparse.ArgumentParser(
        description='Script to get a physical page address (in the current context)'
                    'given a process selector script and a specification\n'
                    'Must be root to run this p')
    parser.add_argument('--script', '-s', metavar='script', type=str, required=True, help='Script under the ps folder')
    parser.add_argument('--region', '-r', metavar='memory_regions', type=str, choices=('stack', 'heap', 'vdso', 'vvar'),
                        required=True, help='Area from possible addresses to obtain, one of: %(choices)s', )
    parser.add_argument('--order', '-o', metavar='page-order', type=str, choices=('first', 'last', 'random'),
                        default='first', required=True,
                        help='The order of the page to return, one of: %(choices)s')
    parser.add_argument('--debug', '-d', action='store_true', required=False, default=False,
                        help='Enable printing debug messages')
    parser.add_argument('--verbose', '-v', action='store_true', required=False, default=False,
                        help='Print additional information')

    args = parser.parse_args()

    DEBUG = args.debug

    # Validate all values

    # Start Script
    script_logger = ScriptLogger(__file__, debug=DEBUG, mute_console=not args.verbose)
    logger = script_logger.get_main_logger()

    logger.debug("Starting domU broker with: {}".format(args))

    logger.info("Invoking script {}".format(args.script))
    try:
        pid = int(run_cmd("ps/{}".format(args.script)))
        logger.info("Pid returned {}".format(pid))
    except subprocess.CalledProcessError as e:
        logger.error("Could not acquire the pid\n:{}".format(e))
        logger.error("!! {}".format(traceback.format_exc()))
        exit(1)

    cmd = "python3 page_selector.py --pid {} --region {} --order {}".format(pid, args.region, args.order)
    logger.info("Will invoke the command:\n{}".format(cmd))
    try:
        gpfn = run_cmd(cmd)
    except subprocess.CalledProcessError as e:
        logger.error("Could not acquire the gpfn\n:{}".format(e))
        logger.error("!! {}".format(traceback.format_exc()))
        exit(1)

    logger.info("Returned the GPFN {}".format(gpfn))
    print(gpfn)
