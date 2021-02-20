import subprocess as sp
# get all pid that refeers to vconnector
from ps_utils import shell_cmd

pid_l = shell_cmd("ps aux | grep vconnector | awk '{print $2}'").split()
j_pid = shell_cmd("pgrep java").split()

p = [x for x in j_pid if x in pid_l]

if p and len(p) == 1:
    print(p[0])
    exit(0)
else:
    if len(p) > 1:
        print("More than one PID")
        print(p[0])
        exit(len(p))
exit(-1)

