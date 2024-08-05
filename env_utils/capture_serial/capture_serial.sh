#!/bin/bash
#

LOG_DATE=$(date +%Y%m%d%H%M%S)
screen -L -Logfile serial_console_${LOG_DATE}.log sudo virsh console l1v4-18
