echo 'GRUB_DISABLE_OS_PROBER=true
GRUB_CMDLINE_XEN_DEFAULT="dom0_mem=4096M,max:4096M loglvl=all guest_loglvl=all \
dom0_max_vcpus=2 com1=115200,8n1,0xd8c0,18 console=com1,vga sync_console \
mce_verbosity=verbose mce=off"
GRUB_DEFAULT="Ubuntu GNU/Linux, with Xen hypervisor"
'> /etc/default/grub.d/xen.cfg



# Change the Grub
update-grub

for i in \
	xenconsoled.service \
	xenstored.service \
	xendomains.service \
	xendomains.service \
	xen-watchdog.service \
	xen.service \
	xen-init-dom0.service \
	xen-qemu-dom0-disk-backend.service; 
do
	sudo systemctl enable $i
done



for i in \
	xenconsoled.service \
	xenstored.service \
	xendomains.service \
	xendomains.service \
	xen-watchdog.service \
	xen.service \
	xen-init-dom0.service \
	xen-qemu-dom0-disk-backend.service; 
do
	sudo systemctl status $i
done