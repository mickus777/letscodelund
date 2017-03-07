#!/bin/bash -ex

g++ -std=c++14 -o sample sample.cpp

./sample   > sample_org.txt

./sample r > sample_rand.txt

./sample h > sample_half.txt

rm -f sample
