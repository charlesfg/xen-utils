#!/bin/bash
if test  $(xl list | grep guest01 |wc -l) -eq 0;
then
    xl create /etc/xen/guest01.cfg
sleep 20
fi

GPFN=$(ssh guest01 /root/print_ulong.sh)
GUEST_ID=$(xl list | grep guest01 | awk '{print $2}')
/var/tpcv/xen-utils/attacks/vm2handler/dom0/memory_handler -d $GUEST_ID -a write -p dec -H bff $GPFN | grep 'mfn=0x'
