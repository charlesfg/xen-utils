cd /root
if ! ( screen -ls | grep test > /dev/null); then
    screen -dmS test;
fi
screen -S test -X stuff '/root/xen-utils/understand-xen/domU/x64/change_mem/print_ulong | tee print_ulong.out\n'
sleep 2
PID=$(cat print_ulong.out | grep heap | awk '{print $3}')
ADDR=$(cat print_ulong.out | grep heap | awk '{print $7}')
/root/xen-utils/understand-xen/domU/x64/change_mem/virt_to_phys_user $PID $ADDR
