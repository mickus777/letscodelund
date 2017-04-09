#!/bin/bash -ue
#
# My relese build and no qtcreator
#

set -x

g++ -std=c++14 -O3 -s -o main main.cpp

time ./main < A-small-attempt0.in |tee google.out

rm main
