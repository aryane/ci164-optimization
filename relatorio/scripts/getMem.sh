#!/bin/bash

rm cache.dat 2> /dev/null
for i in 256 257 1024 1025 2048 2049; do
        rm cache$1$i 2> /dev/null
        rate=$(likwid-perfctr -C S0:0 -g MEM ../gradSolverlik -r $i -o out | grep "Memory bandwidth" | awk '{print $6}')
        echo $i $rate >> mem$1.dat
done

rm out
