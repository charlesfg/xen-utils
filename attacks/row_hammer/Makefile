obj-m:=rh_emul_1.o
KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -O2 -Wno-declaration-after-statement

.PHONY: clean run

all: rh_emul.c
	$(MAKE) $(CFLAGS) -C $(KDIR) M=$(PWD) modules -lxenctrl
	
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run: all
	dmesg -C && insmod rh_emul_1.ko && rmmod rh_emul_1 && dmesg
 
  
