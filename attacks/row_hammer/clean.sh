obj=rh_emul
for i in $( ls ${obj}_[0-9].c);
do
    V=$(basename $i .c | sed "s/${obj}_//" | cat)
    bash -x compile.sh $V
    make clean
    rm ${obj}_${V}.c
done 
rm *-safe

