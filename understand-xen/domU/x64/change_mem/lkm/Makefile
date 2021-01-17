obj-m:=print_mem.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

.PHONY: clean run load unload

all: print_mem.c
	$(MAKE) $(CFLAGS) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run: all
	dmesg -C && insmod print_mem.ko && rmmod print_mem && dmesg

load: all
	dmesg -C && insmod print_mem.ko ms_sleep=3000 && dmesg -E
 
unload: all
	rmmod print_mem && dmesg -D
  
