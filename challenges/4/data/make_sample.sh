#!/bin/bash -ex

g++ -std=c++14 -o sample sample.cpp

./sample r > sample_rand.txt

./sample R > sample_rand_big.txt

./sample h > sample_half.txt

for n in $(seq 1 9)
do
  ./sample $n > sample_${n}.txt
done

rm -f sample
