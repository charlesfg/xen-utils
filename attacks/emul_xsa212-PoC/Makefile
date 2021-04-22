obj-m:=xsa212.o
KDIR:=/lib/modules/$(shell uname -r)/build 
PWD:=$(shell pwd)
xsa212-objs:=emul_xsa212.o native.o

.PHONY: clean run

all: emul_xsa212.c 
	$(MAKE) -C $(KDIR) M=$(PWD) modules -lxenctrl

$(KBUILD_EXTMOD)/native.o: native.asm
	nasm -f elf64 -o $@ $^

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run: 
	insmod xsa212.ko
	dmesg 
	rmmod xsa212
