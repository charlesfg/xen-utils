#CFLAG = -I/var/tpcv/xen_install/xen/tools/libxc -I/var/tpcv/xen_install/xen/tools/include -Wall -O2
CFLAG =-I/var/xen-dev/xen/tools/libxc -I/var/xen-dev/xen/tools/include -Wall  -g
CC = /usr/bin/gcc
LDLIBS = -lm -lpthread -lxenctrl -g

vpath %.c ${SRC_PATH}

.PHONY: all clean run
ALL = page_exploiter memory_handler

all: ${ALL}

clean:
	rm -rf ${ALL} *.o 
	clear

%.o: %.c
	${CC} ${CFLAG} -c $^ -o $@

page_exploiter: page_exploiter.o
	${CC} ${CFLAG} $^ ${LDLIBS} -o $@

memory_handler: memory_handler.o
	${CC} ${CFLAG} $^ ${LDLIBS} -o $@

# This requires an specific address
run: ${ALL}
	./change_mem 0x561804000 3 30071980
