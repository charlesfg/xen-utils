MOD=km_xen_ver_5
obj-m:=$(MOD).o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

.PHONY: clean run clear

all: km_xen_ver_5.c
	$(MAKE) $(CFLAGS) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

clear:
	insmod $(MOD).ko clear=1 && rmmod $(MOD) && dmesg

run: all
	dmesg -C && insmod $(MOD).ko && rmmod $(MOD) && dmesg
 
  
