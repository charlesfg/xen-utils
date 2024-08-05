#!/bin/bash -x

MOUNT_POINT=/opt/xen/l1_xen_src
REMOTE_USER=xen
REMOTE_IP=192.168.1.20
REMOTE_PATH=/opt/xen/src

if [ "$1" = "-u" ];
then
	if mountpoint -q "$MOUNT_POINT"; then
		echo "$MOUNT_POINT is being unmounted."
		fusermount -u $MOUNT_POINT
		if [ $? -eq 0 ]; then
			echo "unmounted $MOUNT_POINT successfully."
		else
			echo "failed to unmount $MOUNT_POINT."
		fi
	else
		echo "$MOUNT_POINT is not mounted. Nothing to do..."
    fi
else
	if mountpoint -q "$MOUNT_POINT"; then
		echo "$MOUNT_POINT is already mounted."
	else
		echo "$MOUNT_POINT is not mounted. mounting now..."
		sshfs $REMOTE_USER@$REMOTE_IP:$REMOTE_PATH $MOUNT_POINT
		if [ $? -eq 0 ]; then
			echo "mounted $MOUNT_POINT successfully."
		else
			echo "failed to mount $MOUNT_POINT."
        fi
    fi
fi
