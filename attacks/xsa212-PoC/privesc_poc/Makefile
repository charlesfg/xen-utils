obj-m := test.o
test-objs := module.o native.o
$(KBUILD_EXTMOD)/native.o: native.asm
	nasm -f elf64 -o $@ $^
