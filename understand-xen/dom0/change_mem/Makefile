CFLAG =-I/var/xen-dev/xen/tools/libxc -I/var/xen-dev/xen/tools/include -Wall -O2
CC = /usr/bin/gcc
LDLIBS = -lm -lpthread -lxenctrl

vpath %.c ${SRC_PATH}

.PHONY: all clean run
ALL = change_mem 

all: ${ALL}

clean:
	rm -rf ${ALL} *.o 
	clear

%.o: %.c
	${CC} ${CFLAG} -c $^ -o $@

change_mem: change_mem.o
	${CC} ${CFLAG} $^ ${LDLIBS} -o $@

# This requires an specific address
run: ${ALL}
	./change_mem 0x561804000 3 30071980
