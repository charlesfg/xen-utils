#!/bin/bash -x
set -e
make -j distclean
make -j clean
# configure debug build 
make -C xen menuconfig
./configure  --enable-systemd --with-system-qemu=/usr/bin/qemu-system-i386 --disable-docs --disable-stubdom 
make dist-xen
make dist-tools

