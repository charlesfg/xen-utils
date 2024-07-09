#!/bin/bash


HOSTS=(192.168.1.20 192.168.1.30 192.168.1.22 172.16.0.13 172.16.0.14)
HOST=(l1 sysc cvm sysb mon)
if [ "$1" == "all" ]; then
    echo  " == Check all hosts in the environment"
    sleep 0.5
    for i in ${HOSTS[@]}; do
        echo $i
        ssh $i /bin/bash connectivity_check.sh
    done
    exit 0;
fi    



# Define target IPs
targets=(192.168.1.20 192.168.1.22 172.16.0.13 10.3.2.220)
google_url="8.8.8.8"  # Google DNS for internet check



# Function to perform ping test and report results
ping_check() {
  local target="$1"
  
  ping -c 3 -q "$target" &> /dev/null
  if [[ $? -eq 0 ]]; then
    echo "Successfully pinged $target"
  else
    echo "Error: Could not ping $target from $my_ip"
  fi
}

# Check connectivity to each target and internet
echo "** Checking connectivity from $my_ip **"
for target in "${targets[@]}"; do
  ping_check "$target"
done

ping_check "$google_url"  # Check internet connectivity

# Additional network checks (optional)
# You can uncomment and modify these commands for further checks:

# Check route to specific subnet
# route -n | grep 172.16.0.0/16

# Check firewall rules (iptables)
# iptables -L INPUT -n | grep -v "^Chain"

echo "** Finished network checks **"

