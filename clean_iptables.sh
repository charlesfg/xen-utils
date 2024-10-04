sudo iptables -F
sudo iptables -X
sudo iptables -t nat -F
sudo iptables -t nat -X
sudo iptables -t mangle -F
sudo iptables -t mangle -X
sudo iptables -t raw -F
sudo iptables -t raw -X

sudo iptables -P INPUT ACCEPT
sudo iptables -P FORWARD ACCEPT
sudo iptables -P OUTPUT ACCEPT

sudo iptables-save > /etc/iptables/rules.v4
cat /etc/iptables/rules.v4

sudo systemctl restart iptables
# or
sudo systemctl restart netfilter-persistent

sudo iptables-save
