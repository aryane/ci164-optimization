#!/bin/bash

rm -f ../cache${1}.dat
for i in 256 257 1024 1025 2048 2049; do
    for ((j=0; j<10; j++)); do
        missrate=$(likwid-perfctr -C S0:0 -g CACHE ../../bin/grad${1} -r $i | grep "cache misses" | awk '{print $6}')
        echo $i $missrate >> temp$i
    done
    cat temp$i | sort -n | head -1 >> ../cache${1}.dat
    rm temp$i
done
