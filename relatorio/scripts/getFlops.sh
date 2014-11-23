#!/bin/bash

export LANG=C
export LC_ALL=C

rm -f ../flops${1}.dat
for i in 256 257 1024 1025 2048 2049; do
    for ((j=0; j<10; j++)); do
        likwid-perfctr -C S0:0 -g FLOPS_DP ../../bin/grad$1 -r $i |\
            sed -e "s:|::g" -e "s:  : :g" |  awk -v NNN=${i} '
        /DP MFlops/{ MFlops=$3 * 1.0 ; }
        /unhalted/ { time=$4 * 1.0 ; }
        END{ printf "%d %.3f\n", NNN, (MFlops * time * 1048576.0) }' \
            >> temp$i
    done
    cat temp$i | sort -n | head -1 >> ../flops${1}.dat
    rm temp$i
done
