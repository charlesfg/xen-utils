#!/bin/bash
cp rh_emul.c rh_emul_${1}.c
sed "s/XXX/${1}/g" Makefile_pttrn > Makefile

