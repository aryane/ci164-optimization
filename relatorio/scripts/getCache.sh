#!/bin/bash

rm -f ../cache${1}.dat
for i in 256 257 1024 1025 2048 2049; do
        missrate=$(likwid-perfctr -C S0:0 -g CACHE ../../bin/grad${1} -r $i | grep "miss rate" | awk '{printf "%f\n",$7}')
        echo $i $missrate >> ../cache${1}.dat
done
