set -e
ld -v
wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.gz
tar -xvzf binutils-2.35.tar.gz 
cd binutils-2.35/
./configure --prefix=/usr
make
sudo make install
ld -v
