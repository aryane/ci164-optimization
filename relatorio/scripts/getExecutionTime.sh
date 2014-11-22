#!/bin/bash

rm execucoes.dat 2> /dev/null
for i in 32 33 256 257 1024 1025 2048 2049; do
    rm exec$i 2> /dev/null
    for ((j=0; j<10; j++)); do
        likwid-pin -c 0 ../gradSolver -r $i -k 50 | grep "#Tempo Grad:" | awk \
            '{print $3}' | sed -e 's/s$//' >> exec$i
    done
    echo $i $(cat exec$i | sort -n | head -1) >> execucoes.dat
    rm exec$i
done
