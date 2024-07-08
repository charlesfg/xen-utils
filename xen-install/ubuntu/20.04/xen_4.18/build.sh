make clean -j 

./configure \
	--enable-systemd \
	--enable-debug

make debug=y -j	2


sudo make install

sudo /sbin/ldconfig
