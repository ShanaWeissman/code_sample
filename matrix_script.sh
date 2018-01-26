#!/bin/bash

g++ MatrixMultiplication.cpp -o mat.out

n=64
while [ $n -le 400 ]
do
	echo "the program will be run with $n by $n matrices"
	echo "the time for matrix multiplication is:"
	./mat.out $n
	((n = n + 64 ))
done
