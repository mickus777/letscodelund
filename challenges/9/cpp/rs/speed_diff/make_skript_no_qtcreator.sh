#!/bin/bash -ue
#
# My relese build and no qtcreator
#
# ./make_skript_no_qtcreator.sh + + + + + / / / / / x x x x x
#

SRC="main.cpp"

set -x

g++ -std=c++14 -O2 -s -D SKRIPT_RUN -o mymain  $SRC

set +x

for typ in $@
do
  echo "time ./mymain $typ"
  time ./mymain $typ
done

#set -x

#g++ -std=c++14 -O3 -s -o main main.cpp  ord.cpp

#time ./main < A-small-attempt0.in |tee google.out

rm mymain
