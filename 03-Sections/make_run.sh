#! /bin/bash

export OMP_NUM_THREADS=4
make all
./run
make clean