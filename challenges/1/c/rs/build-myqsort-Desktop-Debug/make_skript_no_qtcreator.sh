#!/bin/bash -ue
#
# My relese build and no qtcreator
#

gcc -O2 -s -o myqsort ../myqsort/main.c -I ../myqsort/ -I .

./myqsort >out.txt
