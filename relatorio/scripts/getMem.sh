#!/bin/bash

rm -f ../mem$1
for i in 256 257 1024 1025 2048 2049; do
        mem=$(likwid-perfctr -C S0:0 -g MEM ../../bin/grad$1 -r $i | grep "Memory bandwidth" | awk '{print $6}')
        echo $i $mem>> ../mem$1.dat
done
