#!/bin/bash

# Define the directory to store backups

# Check if the script is running as root
# if [[ $(id -u) -ne 0 ]]; then
# 	echo "This script must be run as root. Exiting."
# 	exit 1
# fi

backup_dir="conf_bkp_$(date +"%Y%m%d_%H%M%S")"
mkdir "$backup_dir" || { echo "Failed to create backup directory"; exit 1; }

# Dump XML configurations of domains
sudo virsh list --all --name | while read -r domain; do
    sudo virsh dumpxml "$domain" > "$backup_dir/${domain}.xml"
done

# Dump XML configurations of defined networks
sudo virsh net-list --all --name | while read -r network; do
    sudo virsh net-dumpxml "$network" > "$backup_dir/${network}_network.xml"
done

# Dump XML configurations of storage pools
sudo virsh pool-list --all --name | while read -r pool; do
    sudo virsh pool-dumpxml "$pool" > "$backup_dir/${pool}_storage_pool.xml"
done



# Define list of hosts with their IP addresses
declare -A hosts=(
    ["l1v4-18"]="192.168.1.20"
    ["sysclient"]=192.168.1.22
    ["cvm"]=172.16.0.10
    ["sysbench"]=172.16.0.14
)


# Copy Xen configuration files from predefined hosts
for h in "${!hosts[@]}"; do
    mkdir -p  "$backup_dir/${h}_xen_cfg/"
    scp "root@${hosts[$h]}:/etc/netplan/*" "$backup_dir/${h}_xen_cfg/"
    scp "root@${hosts[$h]}:/etc/network/interfaces" "$backup_dir/${h}_xen_cfg/"
done

scp "root@${hosts["l1v4-18"]}:/etc/xen/*.cfg" "$backup_dir/l1v4-18_xen_cfg/"

# Define list of commands to execute on each VM
# cmds=(
#     "command1"
#     "command2"
#     # Add more commands as needed
# )
# 
# # Execute commands on each VM
# for h in "${!hosts[@]}"; do
#     ssh "${hosts[$h]}" "${cmds[@]}"
# done

# Move all XML files to the backup directory
#mv *.xml "$backup_dir/"

echo "Backup completed successfully. Files are stored in $backup_dir"

