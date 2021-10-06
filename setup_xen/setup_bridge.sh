#!/bin/bash -x



cat <<\EOF>>/etc/network/interfaces
auto xenbr0                                                                                         
iface xenbr0 inet static                                                                            
        bridge_ports none                                                                           
        bridge_stp no                                                                               
        address 192.168.1.1                                                                         
        netmask 255.255.255.0                                                                       
        network 192.168.1.0                                                                         
        broadcast 192.168.1.255    
up route add -net 192.168.1.0/24 gw 192.168.1.1 dev xenbr0
EOF


sudo sysctl -w net.ipv4.ip_forward=1

sudo iptables -A FORWARD --in-interface xenbr0 -j ACCEPT
sudo iptables --table nat -A POSTROUTING --out-interface enp0s25 -j MASQUERADE

sudo apt-get install iptables-persistent

