#!/bin/bash -ue
#
# My relese build and no qtcreator
#

g++ -std=c++14 -O2 -s -o myqsort ../myqsort/main.cpp ../myqsort/system.cpp -I ../myqsort/ -I .

./myqsort >out.txt

