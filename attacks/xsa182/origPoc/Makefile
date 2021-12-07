KDIR = /lib/modules/$(shell uname -r)/build
obj-m += xsa-182-poc.o

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

run:
	insmod xsa-182-poc.ko && dmesg && rmmod xsa-182-poc
