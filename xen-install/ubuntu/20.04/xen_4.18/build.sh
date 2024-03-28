make clean -j

./configure \
	--enable-systemd \
	--enable-debug

make debug=y -j	


sudo make install

sudo /sbin/ldconfig