#!/usr/bin/sh
g++ -fdiagnostics-color=always -g ./main.cpp -o ./test
valgrind --leak-check=full ./test