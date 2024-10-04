#!/bin/bash


cd /tmp
# Download and install Node Exporter
wget https://github.com/prometheus/node_exporter/releases/download/v1.8.1/node_exporter-1.8.1.linux-amd64.tar.gz
tar -xzf node_exporter-1.8.1.linux-amd64.tar.gz
cd node_exporter-1.8.1.linux-amd64

# Move binary to a proper location
sudo mv node_exporter /usr/local/bin/

# Create a systemd service file
sudo useradd -rs /bin/false node_exporter
sudo cp node_exporter.init.d /etc/init.d/node_exporter 
sudo chmod +x /etc/init.d/node_exporter

sudo update-rc.d node_exporter defaults
sudo update-rc.d node_exporter enable

sudo service node_exporter start
