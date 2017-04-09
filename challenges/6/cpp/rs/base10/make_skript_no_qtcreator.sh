#!/bin/bash -ue
#
# My relese build and no qtcreator
#

set -x

g++ -std=c++14 -O3 -s -o main main.cpp

./main < B-small-attempt2.in |tee B-small.out

rm main
