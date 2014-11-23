#!/bin/bash

rm -f ../mem${1}.dat
for i in 256 257 1024 1025 2048 2049; do
    for ((j=0; j<10; j++)); do
        mem=$(likwid-perfctr -C S0:0 -g MEM ../../bin/grad$1 -r $i | grep "Memory bandwidth" | awk '{print $6}')
        echo $i $mem>> temp$i
    done
    cat temp$i | sort -n | head -1 >> ../mem${1}.dat
    rm temp$i
done
