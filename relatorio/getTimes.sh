#!/bin/bash

for i in 32 33 256 257 1024 1025 2048 2049; do
    for ((j=0; j<10; j++)); do
        likwid-pin -c 0 ./gradSolver -r $i -k 50 | grep "#Tempo Grad:" >> temp$i
    done
    cat temp$i | awk '{print $3}' | sed -e 's/s$//'| sort -n > out$i
    rm temp$i
done
