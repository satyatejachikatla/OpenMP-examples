#! /bin/bash

export OMP_NUM_THREADS=4
make all CFLAGS="-DN=8"
./run
make clean