#!/bin/bash

./getExecutionTime.sh

for i in Lambda Residue; do
    ./getCache.sh $i
    ./getMem.sh $i
    ./getFlops.sh $i
done
