#!/bin/bash

# Function to check if Xen is installed
check_xen() {
    command -v xl &> /dev/null && sudo xl info &> /dev/null
}

# Function to check if KVM is installed
check_kvm() {
    command -v virsh &> /dev/null && sudo virsh --version &> /dev/null
}

check_vm_ssh_accessibility() {
    local VM_IP="$1"
    local SSH_USER="$2"

    ./wait-for-it.sh "${VM_IP}:22" --timeout=60 --strict -- echo "$VM_IP ready"

    ssh -o ConnectTimeout=5 -o BatchMode=yes -o StrictHostKeyChecking=no ${SSH_USER}@${VM_IP} exit
    return $?
}

check_if_xen_vm_running() {
    local VM_NAME="$1"
    sudo xl list | grep -q ${VM_NAME}
    return $?
}

check_if_kvm_vm_running() {
    local VM_NAME="$1"
    sudo virsh list --all | grep ${VM_NAME} | grep -q running 
    return $?
}


# Function to check all hosts in a round-robin fashion
check_all_vms() {
    local hosts=("$@")
    local all_up=false

    while [ $attempt -lt $OVERALL_MAX_ATTEMPTS ]; do
        all_up=true

        for VM_IP in "${hosts[@]}"; do
            echo "Checking VM ${VM_IP} (attempt $(($attempt + 1)))..."
            check_vm_ssh_accessibility "$VM_IP" "$SSH_USER"

            if [ $? -ne 0 ]; then
                echo "VM ${VM_IP} not ready yet."
                all_up=false
            else
                echo "VM ${VM_IP} is up."
            fi
        done

        if [ "$all_up" = true ]; then
            echo "All VMs are up."
            return 0
        fi

        echo "Not all VMs are up yet, retrying in $SLEEP_INTERVAL seconds..."
        sleep $SLEEP_INTERVAL
        ((attempt++))
    done

    echo "Not all VMs started up within the expected time."
    return 1
}

all_up=true
if check_xen; then
    echo "Xen hypervisor detected."
    if ! check_if_xen_vm_running sysbench; then
        sudo xl create /etc/xen/sysbench.cfg
        all_up=false
    fi
    if ! check_if_xen_vm_running compromised; then
        sudo xl create /etc/xen/compromised.cfg
        all_up=false
    fi
    sudo xl list
else
    echo "No supported hypervisor detected. Please install Xen or KVM."
    exit 1
fi

if [ "$all_up" = true ]; then
    echo "All VMs are up."
    exit 0
fi

# Call the function with the list of hosts
# List of VMs and SSH user

HOSTS=("172.16.0.13" "172.16.0.14")
SSH_USER="xen"  
OVERALL_MAX_ATTEMPTS=10  # Overall maximum number of attempts
SLEEP_INTERVAL=5  # Seconds between each overall attempt

# Tracking attempts
attempt=0


if ! check_all_vms "${HOSTS[@]}"; then
    echo "Couldn't bring the hosts up!"
fi

