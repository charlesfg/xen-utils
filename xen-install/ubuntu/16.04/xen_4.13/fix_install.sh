systemctl stop systemd-modules-load.service
rm -rf /etc/modules-load.d/cups-filters.conf
cp -v xencommons /etc/init.d/xencommons
cp -v xen.conf /usr/local/lib/modules-load.d/xen.conf
systemctl start systemd-modules-load.service

