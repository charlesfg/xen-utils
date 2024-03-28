#!/bin/sh
nasm -o hv_shellcode.bin hv_shellcode.asm
echo "uint8_t hv_shellcode[] = {0x$(hexdump -v -e '/1 "%02X "' < hv_shellcode.bin | sed 's# #,0x#g' | sed 's|,0x$||')};" > hv_shellcode.bin.h
nasm -o user_shellcode.bin user_shellcode.asm
echo "uint8_t user_shellcode[] = {0x$(hexdump -v -e '/1 "%02X "' < user_shellcode.bin | sed 's# #,0x#g' | sed 's|,0x$||')};" > user_shellcode.bin.h
make -C /lib/modules/$(uname -r)/build M=$(pwd)
gcc -o attack attack.c -Wall -std=gnu99
sync

