#!/bin/bash


function die() {
    echo "[ERROR] : Script needed!"
    echo "Use: $0 [script to execute]"
    exit 1;
}

[ "$1" ] || die

HOSTS=(localhost 192.168.1.20 192.168.1.30 192.168.1.22 172.16.0.13 172.16.0.14)
#HOSTS=(l1 sysc cvm sysb mon)
SCRIPT_TO_RUN="$1"

echo  " == Executing the script '$1' in all environments' hosts"
sleep 0.5
for i in ${HOSTS[@]}; do
    echo "Executing on host $i"
    scp ${SCRIPT_TO_RUN} ${i}:~
    ssh $i /bin/bash ${SCRIPT_TO_RUN}
done
exit 0;
