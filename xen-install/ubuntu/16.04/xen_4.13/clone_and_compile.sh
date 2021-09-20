git clone git://xenbits.xen.org/xen.git
cd xen
git checkout RELEASE-4.13.0


./configure --libdir=/usr/lib
make dist
