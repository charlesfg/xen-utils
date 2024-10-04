#/bin/bash
for i in $(sudo  xl list | grep -v Domain-0  | grep -v ^Name| awk '{print $2}');
do 
    echo $i
    sudo xl shutdown $i
done
sleep 3
sudo xl list
