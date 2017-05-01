#!/bin/bash -ue
#
# My relese build and no qtcreator
#
SRC="main.cpp  ord.cpp"

set -x

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mymain  $SRC

./mymain $@
#set -x

#g++ -std=c++14 -O3 -s -o main main.cpp  ord.cpp

#time ./main < A-small-attempt0.in |tee google.out

rm mymain
