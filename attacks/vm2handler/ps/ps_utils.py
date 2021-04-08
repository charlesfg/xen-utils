from subprocess import check_output as co


def shell_cmd(shell_cmd):
    try:
        return co(shell_cmd, shell=True)
    except:
        return ""



