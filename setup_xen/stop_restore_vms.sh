#!/bin/bash -x
sed -i "/XENDOMAINS_RESTORE=true/ s/true/false/g" /etc/default/xendomains
