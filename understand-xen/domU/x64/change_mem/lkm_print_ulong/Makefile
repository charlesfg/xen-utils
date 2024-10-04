obj-m += print_ulong_1.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

.PHONY: clean run load unload

all: print_ulong_1.c
	$(MAKE) $(CFLAGS) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run: all
	dmesg -C && insmod print_ulong_1.ko addr=$(ADDRESS) value=$(VALUE) && rmmod print_ulong_1 && dmesg
 
load: 
	dmesg -C && insmod print_ulong_1.ko 

unload:
	rmmod print_ulong_1 && dmesg
