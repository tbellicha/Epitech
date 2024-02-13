#!/usr/bin/env bash

rm *.o

gcc -Wall -c my*.c

ar rc libmy.a *.o

ar -t libmy.a

rm *.o
