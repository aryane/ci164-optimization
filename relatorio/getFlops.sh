#!/bin/bash

for i in 32 33 256 257 1024 1025 2048 2049; do
    for ((j=0; j<10; j++)); do
        likwid-perfctr -C S0:0 -g FLOPS_DP ./gradSolverlik -r $i -o out | grep "FP_COMP_OPS_EXE_SSE_DOUBLE_PRECISION" | awk '{print $4}' >> flops$1$i
    done
done

rm out
