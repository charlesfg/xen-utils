#!/bin/bash -x


cd /tmp
wget wget https://www.kernel.org/pub/linux/utils/util-linux/v2.38/util-linux-2.38.tar.xz
sudo apt install build-essential
sudo apt build-dep util-linux
tar xvf util-linux-2.38.tar.xz
cd util-linux-2.38
./configure
make 
sudo make install
