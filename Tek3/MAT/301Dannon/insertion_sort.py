#!/usr/bin/env python3


def sort(arr):
    comparisons = 0
    n = len(arr)
    tmp_array = arr.copy()
    for i in range(1, n):
        j = i
        while j > 0:
            comparisons += 1
            if tmp_array[j - 1] <= tmp_array[j]:
                tmp_array[j], tmp_array[j - 1] = tmp_array[j - 1], tmp_array[j]
                j -= 1
            else:
                break
    return comparisons
