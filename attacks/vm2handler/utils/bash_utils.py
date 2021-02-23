import traceback
from time import sleep

import subprocess
import logging

import re

import sys

__null_logger = logging.getLogger("dummy_null_logger")


def linux_which(cmd):
    return run_cmd("which {}".format(cmd))


def grep(cmd_output, what):
    lines = cmd_output.split('\n')
    result = []
    for l in lines:
        if re.findall(r'{}'.format(what), l):
            result.append(l)
    return '\n'.join(result)


def sleep_print(i):
    for x in range(1, i):
        print("."),
        sys.stdout.flush()
        sleep(1)
    sleep(1)
    print(".")
    sys.stdout.flush()


def wait_and_check(cond, tries, t_sleep, use_inverse=False):
    """

    :param cond: Function to test if the condition is achieved
    :param tries: Number of times to try checking the condition
    :param t_sleep: number of seconds to sleep, it will be multiplied by the try number to create
    an factorial sleep process
    :param use_inverse: If the goal is achieved by False rather then True
    :return:  True if the condition was achieved of False if the number of tries was reached
    """
    count = 0

    while True:
        sleep_print(t_sleep)
        cond_ret = cond()
        if use_inverse:
            cond_ret = not cond_ret
        if cond_ret:
            return True
        else:
            count += 1
        if count >= tries:
            return False


def execute_or_abort(cmd, err_msg, cmd_msg=None, log=None):
    logger = log or __null_logger
    msg = cmd_msg or "Will invoke the command:"
    logger.info("{}\n{}".format(msg, cmd))
    try:
        output = run_cmd(cmd)
    except subprocess.CalledProcessError as e:
        logger.error("{}\n:{}".format(err_msg, e))
        logger.error("\n\tError Output:\n{}\n".format(e.output))
        logger.error("!! {}".format(traceback.format_exc()))
        exit(1)
    return output


def run_cmd(cmd, timeout=2):
    # will crash (intentionally if do not work for more then 3 times
    count = 0
    while True:
        try:
            output = subprocess.check_output(cmd, shell=True, stderr=subprocess.STDOUT, timeout=timeout)
            return output.strip().decode('utf-8')
        except subprocess.TimeoutExpired as t:

            if count < 3:
                count += 1
            else:
                raise t


def run_cmd_ignore(cmd, timeout=2):
    # will ignore (intentionally) if do not work for more then 3 times
    count = 0
    while True:
        try:
            output = subprocess.check_output(cmd, shell=True, stderr=subprocess.STDOUT, timeout=timeout)
            return output.strip()
        except subprocess.TimeoutExpired:
            if count < 3:
                count += 1
            else:
                return "Error Timeout"
        except subprocess.CalledProcessError:
            return None


DMESG = linux_which('dmesg')


def dmesg(clear=True):
    if clear:
        return run_cmd(DMESG + " -c")
    return run_cmd(DMESG)


if __name__ == '__main__':
    print(bool(grep(run_cmd("ls -a ~"), '^\.dXXX')))
