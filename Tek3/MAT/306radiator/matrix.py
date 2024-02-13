#!/usr/bin/env python3
H = 0.5
XIRYJR = -300.0


def pivot_y(matrix, j):
    y = j
    for i in range(j, len(matrix)):
        if abs(matrix[i][j]) > abs(matrix[y][j]):
            y = i
    return y


def fill_mats(matrix, tmp_matrix, i, j, res_div):
    matrix[i] = [one + two for one, two in zip(matrix[i], [x * res_div for x in matrix[j]])]
    tmp_matrix[i] = tmp_matrix[i] + res_div * tmp_matrix[j]


def gaussian_matrix(matrix, n, ir, jr):
    gauss_matrix = [0.0 for _ in range(n**2)]
    tmp_matrix = [0.0 for _ in range(n**2)]
    tmp_matrix[ir * n + jr] = XIRYJR
    for i in range(0, len(matrix) - 1):
        j = pivot_y(matrix, i)
        matrix[i], matrix[j] = matrix[j], matrix[i]
        tmp_matrix[i], tmp_matrix[j] = tmp_matrix[j], tmp_matrix[i]
        for k in range(i + 1, len(matrix)):
            fill_mats(matrix, tmp_matrix, k, i, (float(matrix[k][i]) * -1.0) / float(matrix[i][i]))
    for y in range(len(matrix) - 1, -1, -1):
        for x in range(i + 1, len(matrix)):
            tmp_matrix[y] = tmp_matrix[y] - float(matrix[y][x]) * gauss_matrix[x]
        gauss_matrix[y] = tmp_matrix[y] / float(matrix[y][y])
    return gauss_matrix


def display_matrix(matrix):
    for line in matrix:
        string_array = [str(elem) for elem in line]
        print('\t'.join(string_array))


def reset_matrix(matrix, s, t):
    for i in range(s, t):
        matrix[i][i] = 1


def set_matrix(matrix, n, off_y):
    y = 0
    for i in range(n + 1 + off_y, 2 * n - 1 + off_y):
        x = 0
        xn = 0
        point = [1 + y + off_y, n + y + off_y, n + y + 1 + off_y, n + y + 2 + off_y, 2*n + y + 1 + off_y]
        coefficient = [1, 1, -4, 1, 1]
        for p in range(len(matrix[i])):
            if x in point:
                matrix[i][x] = int((1 / H**2) * coefficient[xn])
                xn += 1
            x += 1
        y += 1
    reset_matrix(matrix, 2*n - 1 + off_y, 2*n + 1 + off_y)
    return y + 2


def init_matrix(n):
    matrix = [[0 for y in range(n**2)] for x in range(n**2)]
    reset_matrix(matrix, 0, n + 1)
    off_y = 0
    while off_y + n < n**2-1 - n:
        off_y = off_y + set_matrix(matrix, n, off_y)
    reset_matrix(matrix, n + off_y, n**2)
    return matrix
