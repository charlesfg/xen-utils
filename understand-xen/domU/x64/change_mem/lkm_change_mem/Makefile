obj-m:=change_mem_4.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

ADDRESS=0xffff
VALUE=0


.PHONY: clean run load unload

all: change_mem_4.c
	$(MAKE) $(CFLAGS) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run: all
	dmesg -C && insmod change_mem_4.ko addr=$(ADDRESS) value=$(VALUE) && rmmod change_mem_4 && dmesg
  
