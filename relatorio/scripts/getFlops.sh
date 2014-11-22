#!/bin/bash

export LANG=C
export LC_ALL=C

rm -f flops${1}.dat 2> /dev/null
for i in 256 257 1024 1025 2048 2049; do
   likwid-perfctr -C S0:0 -g FLOPS_DP ../gradSolverlik -r $i -o out |\
   sed -e "s:|::g" -e "s:  : :g" |  awk -v NNN=${i} '
	/DP MFlops/{ MFlops=$3 * 1.0 ; }
	/unhalted/ { time=$4 * 1.0 ; }
	END{ printf "%d %.3f\n", NNN, (MFlops * time) }' \
   >> flops${1}.dat
done

rm -f out
