# check the update_binutils

update-alternatives --remove-all ld
update-alternatives --remove-all as



update-alternatives --remove-all as


update-alternatives --install /usr/bin/ld ld /usr/bin/ld-bu-2.35 10
update-alternatives --install /usr/bin/ld ld /usr/local/bin/ld-bu-2.30 20

update-alternatives --install /usr/bin/as as /usr/bin/as-bu-2.35 10
update-alternatives --install /usr/bin/as as /usr/local/bin/as-bu-2.30 20






