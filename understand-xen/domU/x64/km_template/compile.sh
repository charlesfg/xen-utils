
cp km_xen_ver.c km_xen_ver_${1}.c
sed "s/XXX/${1}/g" Makefile_pttrn > Makefile

