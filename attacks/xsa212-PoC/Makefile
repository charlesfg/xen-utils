obj-m:=test.o
KDIR:=/lib/modules/$(shell uname -r)/build 
PWD:=$(shell pwd)
test-objs:=module.o native.o

.PHONY: clean run

all: module.c 
	$(MAKE) -C $(KDIR) M=$(PWD) modules -lxenctrl

$(KBUILD_EXTMOD)/native.o: native.asm
	nasm -f elf64 -o $@ $^

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean 

run:
	dmesg -c
	insmod test.ko
	rmmod test
	dmesg
