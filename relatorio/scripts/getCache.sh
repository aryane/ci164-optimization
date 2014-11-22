#!/bin/bash

rm cache.dat 2> /dev/null
for i in 256 257 1024 1025 2048 2049; do
        rm cache$1$i 2> /dev/null
        rate=$(likwid-perfctr -C S0:0 -g CACHE ../gradSolverlik -r $i -o out | grep "miss rate" | awk '{print $7}')
        echo $i $rate >> cache$1.dat
done

rm out
