#!/usr/bin/env python3
import sys
from matrix import *


def display_matrix_and_vector(n, ir, jr):
    matrix = init_matrix(n)
    display_matrix(matrix)
    print('')
    gauss_matrix = gaussian_matrix(matrix, n, ir, jr)
    for elem in gauss_matrix:
        print(round(elem + 0.001, 1))


def display_point(n, ir, jr, i, j):
    matrix = init_matrix(n)
    gauss_matrix = gaussian_matrix(matrix, n, ir, jr)
    print(round(gauss_matrix[n * i + j] + 0.001, 1))


def process(argv):
    try:
        n = int(argv[1])
        ir = int(argv[2])
        jr = int(argv[3])
        if n < 1 or (ir * n + jr) > n**2:
            return 84
        if len(argv) == 4:
            display_matrix_and_vector(n, ir, jr)
        if len(argv) == 6:
            i = int(argv[4])
            j = int(argv[5])
            if (n * i + j) > n**2:
                return 84
            display_point(n, ir, jr, i, j)
    except:
        return 84
