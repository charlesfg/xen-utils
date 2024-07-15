#!/bin/bash

# Define the NTP server to be added
NTP_SERVER="ntp.dei.uc.pt"

# Function to configure systemd-timesyncd
configure_systemd_timesyncd() {
    echo "Configuring systemd-timesyncd..."
    
    # Create the configuration directory if it doesn't exist
    sudo mkdir -p /etc/systemd/system/systemd-timesyncd.service.d
    
    # Create or modify the override file
    echo "[Time]
NTP=$NTP_SERVER" | sudo tee /etc/systemd/timesyncd.conf > /dev/null

    # Restart the service to apply changes
    sudo systemctl restart systemd-timesyncd

    echo "systemd-timesyncd configured with NTP server $NTP_SERVER"
}



sudo apt-get install ntp
sudo apt install systemd-timesyncd

# Check which NTP service is installed and configure accordingly
if systemctl is-active --quiet systemd-timesyncd; then
    configure_systemd_timesyncd
else
    echo "Neither systemd-timesyncd nor chrony is active. Please install and enable one of them."
    exit 1
fi

sudo timedatectl set-timezone 'Europe/Lisbon'
sudo timedatectl set-ntp on
sudo timedatectl status
