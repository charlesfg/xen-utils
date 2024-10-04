#!/bin/bash

# Define the directory to store backups

# Check if the script is running as root



# Define list of hosts with their IP addresses
declare -A hosts=(
    ["l1v4-18"]="192.168.1.20"
    ["sysclient"]=192.168.1.22
    ["cvm"]=172.16.0.10
    ["sysbench"]=172.16.0.14
)


# Copy Xen configuration files from predefined hosts
for h in "${!hosts[@]}"; do
    ssh-copy-id -i ~/.ssh/id_ed25519 "root@${hosts[$h]}"
    ssh "root@${hosts[$h]} whoami" 
done

