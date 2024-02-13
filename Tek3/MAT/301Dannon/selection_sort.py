#!/usr/bin/env python3


def sort(arr):
    comparisons = 0
    tmp_array = arr.copy()
    n = len(tmp_array)
    for i in range(0, n - 1):
        min_index = i
        for j in range(i + 1, n):
            comparisons += 1
            if tmp_array[j] < tmp_array[min_index]:
                min_index = j
        tmp_array[min_index], tmp_array[i] = tmp_array[i], tmp_array[min_index]
    return comparisons
