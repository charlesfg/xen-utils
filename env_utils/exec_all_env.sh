#!/bin/bash


function die() {
    echo "[ERROR] : Script needed!"
    echo "Use: $0 [<script|cmds> to execute]"
    exit 1;
}

IS_SCRIPT=true
[ "$1" ] || die

HOSTS=(localhost 192.168.1.20 192.168.1.30 192.168.1.22 172.16.0.13 172.16.0.14)
#HOSTS=(l1 sysc cvm sysb mon)
SCRIPT_TO_RUN="$1"
CP=false
if [ -f "$SCRIPT_TO_RUN" ] && [ -x "$SCRIPT_TO_RUN" ]; then
    # It's an executable file, copy it to the remote host
	CP=true
else
    # It's a command, execute it directly on the remote host
    ssh "$HOST" "$SCRIPT_TO_RUN $@"
fi

echo  " == Executing the script '$1' in all environments' hosts"
sleep 0.5
for i in ${HOSTS[@]}; do
    echo "Executing on host $i"
	if [ "$CP" = true ]; then
    	scp ${SCRIPT_TO_RUN} ${i}:~
        ssh $i /bin/bash ${SCRIPT_TO_RUN}
    else
        ssh $i ${SCRIPT_TO_RUN}
	fi
done
exit 0;
