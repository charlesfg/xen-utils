make -C /lib/modules/$(uname -r)/build M=$(pwd) clean
rm -v attack hv_shellcode.bi* user_shellcode.bi*
