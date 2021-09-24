#!/bin/bash -x

LG_FILE=serial_log_$(date +"%Y%m%d-%H%M").log

ipmitool -I lanplus -H 172.16.203.253 -U admin -P admpasswd sol deactivate 
ipmitool -I lanplus -H 172.16.203.253 -U admin -P admpasswd sol activate | tee ${LG_FILE}
