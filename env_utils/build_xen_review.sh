make clean -j 

./configure \
	--enable-systemd \
	--enable-debug

make debug=y -j	2


sudo make install

sudo /sbin/ldconfig

dist_name="dist_$(git rev-parse --abbrev-ref HEAD)_$(git rev-parse --short HEAD)"

if [ -e ${dist_name} ];
then
    rm -rfv ${dist_name}
fi

mv -v dist ${dist_name}

