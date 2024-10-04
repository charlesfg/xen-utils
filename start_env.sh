#!/bin/bash -x

# Function to check if Xen is installed
check_xen() {
    command -v xl &> /dev/null && sudo xl info &> /dev/null
}

# Function to check if KVM is installed
check_kvm() {
    command -v virsh &> /dev/null && sudo virsh --version &> /dev/null
}

if check_xen; then
    echo "Xen hypervisor detected."
    sudo xl create /etc/xen/sysclient.cfg
    sudo xl create /etc/xen/l1v4.18.cfg
    sudo xl list
elif check_kvm; then
    echo "KVM hypervisor detected."
    sudo virsh create /etc/libvirt/qemu/sysclient.xml
    sudo virsh create /etc/libvirt/qemu/l1v4-18.xml
    sudo virsh list
else
    echo "No supported hypervisor detected. Please install Xen or KVM."
    exit 1
fi

