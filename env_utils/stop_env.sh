#!/bin/bash 


ssh l1 ./stop_env.sh
sudo virsh shutdown monitor
sudo virsh shutdown sysclient
ssh l1 sudo xl list
sudo virsh shutdown l1v4-18

