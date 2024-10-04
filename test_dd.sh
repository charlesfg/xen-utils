#!/bin/bash 

IF=/dev/zero
OF=/tmp/calculate_best_bs.temp
TEST_BLOCK_SIZES=(256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144)
TIMEOUT=20s
BEST_BLOCK_SIZE=0
BEST_BLOCK_SIZE_WROTE=0

for BS in "${TEST_BLOCK_SIZES[@]}"; do
    rm "$OF" >/dev/null 2>&1
    echo 3 >/proc/sys/vm/drop_caches
    timeout "$TIMEOUT" dd "if=$IF" "of=$OF" "bs=$BS" >/dev/null 2>&1
    SIZE=$(stat -c "%s" "$OF")
    if [ "$SIZE" -gt "$BEST_BLOCK_SIZE_WROTE" ]; then
        BEST_BLOCK_SIZE_WROTE="$SIZE"
        BEST_BLOCK_SIZE="$BS"
    fi
done
rm "$OF" >/dev/null 2>&1
echo Fastest Block Size: $BEST_BLOCK_SIZE
