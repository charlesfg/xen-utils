#!/bin/bash -x

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
    if ! check_if_xen_vm_running sysclient; then
        all_up=false
        sudo xl create /etc/xen/sysclient.cfg
    fi
    if ! check_if_xen_vm_running l1v4-18; then
        all_up=false
        sudo xl create /etc/xen/l1v4.18.cfg
    fi
    sudo xl list
elif check_kvm; then
    echo "KVM hypervisor detected."
    if ! check_if_kvm_vm_running sysclient; then
        all_up=false
        sudo virsh create /etc/libvirt/qemu/sysclient.xml
    fi
    if ! check_if_kvm_vm_running l1v4-18; then
        all_up=false
        sudo virsh create /etc/libvirt/qemu/l1v4-18.xml
    fi
    if ! check_if_kvm_vm_running monitor; then
        all_up=false
        sudo virsh create /etc/libvirt/qemu/monitor.xml
    fi
    sudo virsh list
else
    echo "No supported hypervisor detected. Please install Xen or KVM."
    exit 1
fi

if [ "$all_up" = true ]; then
    echo "All VMs are up."
    ./remove_reject_rules.sh
    return 0
else
    sleep 10
fi

# Call the function with the list of hosts
# List of VMs and SSH user

HOSTS=("192.168.1.20" "192.168.1.30" "192.168.1.22")
INNER_HOSTS=("172.16.0.13" "172.16.0.14")
SSH_USER="xen"  
OVERALL_MAX_ATTEMPTS=10  # Overall maximum number of attempts
SLEEP_INTERVAL=5  # Seconds between each overall attempt

# Tracking attempts
attempt=0


check_all_vms "${HOSTS[@]}"

if [ $? -eq 0 ]; then
	echo "Starting inner environment"
	ssh xen@l1 "/bin/bash -x /home/xen/start_env.sh" 
	check_all_vms "${INNER_HOSTS[@]}"
	if [ $? -eq 0 ]; then
		echo "Environment is up and running ... "
        ./remove_reject_rules.sh
		exit 0
    else
        echo "Couldn't bring the hosts up!"
	fi
else
    echo "Couldn't bring the hosts up!"
fi


