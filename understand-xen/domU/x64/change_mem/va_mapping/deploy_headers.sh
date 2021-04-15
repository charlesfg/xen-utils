function help (){
    echo "ERROR: Need header specification"
    echo "$0 <header path>"
    echo "e.g. $0 3.13.0-170"
    
}

[ "$1" ] || { help; exit 1; }

TARGET=$1

for f in $(find ${TARGET} -type f );
do
    echo "Installing $f file"
    t_dir=/usr/src/linux-headers-$(dirname $f)
    if [ -d ${t_dir} ];
    then
        cp -vi $f ${t_dir}/$(basename $f)
    else
        echo "could no install $f file"
    fi
done


#cp -v  /usr/src/linux-headers-3.13.0-170/arch/x86/include/asm/xen/hypercall.h 3.13.0-170/arch/x86/include/asm/xen/  

