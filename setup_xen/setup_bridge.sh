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
