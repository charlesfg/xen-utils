#!/bin/bash
#

# Get the current timestamp
current_timestamp=$(date +%Y%m%d_%H%M%S)


# Check if a parameter is passed
if [ $# -eq 0 ]; then
	log_file="serial_console_${infix}_${current_timestamp}.log"
else
	# Define the variable 'infix' with the parameter passed
	infix=$1
	# Construct the log file name
	log_file="serial_console_${infix}_${current_timestamp}.log"
fi

# Output the log file name (or use it as needed)
echo "Log file name: $log_file"

screen -L -Logfile serial_console_${LOG_DATE}.log sudo virsh console l1v4-18
