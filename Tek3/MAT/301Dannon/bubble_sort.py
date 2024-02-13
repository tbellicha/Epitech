#!/usr/bin/env python3


def sort(arr):
    comparisons = 0
    tmp_arr = arr.copy()
    for i in range(len(tmp_arr)):
        for j in range(len(tmp_arr) - i - 1):
            comparisons += 1
            if tmp_arr[j] > tmp_arr[j + 1]:
                tmp_arr[j], tmp_arr[j + 1] = tmp_arr[j + 1], tmp_arr[j]
    return comparisons
