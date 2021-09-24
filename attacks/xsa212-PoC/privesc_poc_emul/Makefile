obj-m := test.o
test-objs := module.o native.o
$(KBUILD_EXTMOD)/native.o: native.asm
	nasm -f elf64 -o $@ $^


hv_shellcode.bin.h: hv_shellcode.asm
	nasm -o hv_shellcode.bin hv_shellcode.asm
	$(shell echo "uint8_t hv_shellcode[] = {0x$(hexdump -v -e '/1 \"%02X \"' < hv_shellcode.bin | sed 's# #,0x#g' | sed 's|,0x$||')};" > hv_shellcode.bin.h)




clean:
	-rm hv_shellcode.bin
	-rm hv_shellcode.bin.h
