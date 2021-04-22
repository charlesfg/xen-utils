for i in `cat /etc/hosts | grep tpc-g | awk '{print $2}'`; do  
    echo $i; 
    rsync -avz ../vm2handler --exclude '*.pyc' --exclude '*.log'  ${i}:~
done   
