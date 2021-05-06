ld -v
wget https://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.gz
tar -xvzf binutils-2.30.tar.gz 
cd binutils-2.30/
./configure --prefix=/usr/local
make
sudo make install
ld -v
