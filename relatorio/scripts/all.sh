#!/bin/bash

./getExecutionTime.sh
./getExecutionTime.sh Opt

for i in Lambda LambdaOpt Residue ResidueOpt; do
    ./getCache.sh $i
    ./getMem.sh $i
    ./getFlops.sh $i
done
