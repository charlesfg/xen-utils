#!/bin/bash

# List all iptables rules and filter those with the REJECT action
reject_rules=$(sudo iptables -S | grep -- '--reject-with icmp-port-unreachable')

# Check if any reject rules were found
if [ -z "$reject_rules" ]; then
  echo "No REJECT rules found."
  exit 0
fi

# Create and execute commands to remove each REJECT rule
echo "Found the following REJECT rules:"
echo "$reject_rules"
echo ""

echo "Creating and executing iptables commands to remove REJECT rules..."

while IFS= read -r rule; do
  # Replace '-A' with '-D' to create the deletion command
  delete_rule=$(echo "$rule" | sed 's/^-A /-D /')
  echo "Executing: iptables $delete_rule"
  sudo iptables $delete_rule
done <<< "$reject_rules"

echo "All REJECT rules removed."


