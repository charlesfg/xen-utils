obj=change_mem
cp ${obj}.c ${obj}_${1}.c
sed "s/XXX/${1}/g" Makefile_pttrn > Makefile

