obj-m:=km_xen_ver.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

.PHONY: clean run

all: km_xen_ver.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run:
	dmesg -C && insmod km_xen_ver.ko && rmmod km_xen_ver && dmesg
