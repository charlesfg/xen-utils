[ "$1" ] || { echo "Usage $0 [host]"; echo "  host lists: xen-dev, oxum"; exit 1; }

if [ "$1" = "oxum" ];
then
    for i in `cat /etc/hosts | grep tpc-g | awk '{print $2}'`; do  
        echo $i; 
        rsync -avz ../vm2handler --exclude '*.pyc' --exclude '*.log'  ${i}:~
    done
fi

if [ "$1" = "xen-dev" ];
then
    echo "====================\n\tGuest 01 \n"
    rsync -avz ../vm2handler --exclude '*.pyc' --exclude '*.log'  guest01:~
    echo "====================\n\tGuest 02 \n"
    rsync -avz ../vm2handler --exclude '*.pyc' --exclude '*.log'  guest02:~
fi
