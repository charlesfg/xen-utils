#!/bin/bash -x 
make -C /lib/modules/$(uname -r)/build M=$(pwd) $1
