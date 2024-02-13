#!/usr/bin/env python3

import math
import numpy as np
import sys

def parse_file_to_matrix(file_path, size):
    try:
        matrix = np.zeros((size, size))
        with open(file_path, "r") as file:
            for line in file:
                x, y, value = map(int, line.strip().split(";"))
                matrix[x][y] = value
        return matrix
    except Exception as e:
        print(f"An error occured while parsing the file: {e}")
        return None


def binomial_coefficient(n, k):
    return math.factorial(n) / (math.factorial(k) * math.factorial(n - k))


def process(argv):
    matrix = parse_file_to_matrix(argv[2], int(argv[1]))
    if matrix is None:
        return 84
    n = int(argv[1])
    t1 = float(argv[3]) / (n - 1)
    t2 = float(argv[4]) / (n - 1)
    res = 0
    for i in range(n):
        for y in range(n):
            res += binomial_coefficient(n - 1, i) * binomial_coefficient(n - 1, y) * (1 - t1) ** (n - 1 - i) * (1 - t2) ** (n - 1 - y) * t1 ** i * t2 ** y * matrix[i][y]
    print('%.2f' % res)
    return 0