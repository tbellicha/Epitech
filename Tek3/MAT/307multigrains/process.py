#!/usr/bin/env python3
import copy

import classes
import values


def initMatrix(fertilizers, crops):
    matrix = []
    tmp_tab = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ]
    for i in range(0, 4):
        curr_fertilizer_str = "F" + str(i + 1)
        matrix.append([values.all_crops[crops[0].name][curr_fertilizer_str], values.all_crops[crops[1].name][curr_fertilizer_str], values.all_crops[crops[2].name][curr_fertilizer_str],
            values.all_crops[crops[3].name][curr_fertilizer_str], values.all_crops[crops[4].name][curr_fertilizer_str], tmp_tab[i][0], tmp_tab[i][1], tmp_tab[i][2], tmp_tab[i][3], fertilizers[i].quantity])
    matrix.append([-crops[0].price, -crops[1].price, -crops[2].price, -crops[3].price, -crops[4].price, 0, 0, 0, 0, 0])
    return matrix


def getPivot(matrix):
    if 0 <= len(matrix[0]) <= 5:
        return (-1, -1)
    last_index_line = len(matrix[0]) - 1
    last_line_matrix = copy.deepcopy(matrix[len(matrix) - 1])
    if min(last_line_matrix) >= 0:
        return (-1, -1)
    x, y = last_line_matrix.index(min(last_line_matrix)), -1
    value = 8888
    for i, curr_line in enumerate(matrix):
        if curr_line[last_index_line]:
            if curr_line[x] > 0 and (value > (curr_line[last_index_line] / curr_line[x]) and curr_line[last_index_line] / curr_line[x] > 0):
                y = i
                value = curr_line[last_index_line] / curr_line[x]
        elif value > curr_line[x] and curr_line[x] > 0:
            y = i
            value = curr_line[last_index_line] / curr_line[x]
    return (y, x)


def computeMatrix(matrix):
    order = [-1, -1, -1, -1]
    for i in range(1, 6):
        y, x = getPivot(matrix)
        if x < 0 or y < 0:
            break
        pivot = matrix[y][x]
        for k, point_matrix in enumerate(matrix[y]):
            matrix[y][k] /= pivot
        for i, line_matrix in enumerate(matrix):
            if i == y:
                continue
            value = line_matrix[x]
            for j, point_matrix in enumerate(matrix[i]):
                line_matrix[j] -= value * matrix[y][j]
        order[y] = x
    return order, matrix


def reorder(crops, order, matrix):
    good_order = [0, 0, 0, 0, 0]
    for i, curr_order in enumerate(order):
        if curr_order != -1:
            good_order[curr_order] = matrix[i][len(matrix[i]) - 1]
    for i, crop in enumerate(crops):
        crop.computed_quantity = good_order[i]


def process(argv):
    print(f'Resources: ', end='')
    fertilizers = []
    crops = []
    for i in range(1, 5):
        fertilizers.append(classes.Fertilizer(f'F{i}', int(argv[i])))
    for i in range(0, 4):
        if i != 0:
            print(f', ', end='')
        print(f'{fertilizers[i]}', end='')
    print('\n')
    for i in range(0, 5):
        crops.append(classes.Crop(values.all_crops_name[i], argv[i + 5]))
    matrix = initMatrix(fertilizers, crops)
    order, matrix = computeMatrix(matrix)
    reorder(crops, order, matrix)
    for i, crop in enumerate(crops):
        print(f'{crop}')
    print(f'\nTotal production value: ${matrix[-1][-1]:.2f}')
    return 0
