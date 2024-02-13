#!/usr/bin/env python3.10

def algorithm(arr, comparisons):
    n = len(arr)
    if n > 1:
        middle_array = n // 2
        right_middle_array = arr[middle_array:]
        left_middle_array = arr[:middle_array]
        comparisons = algorithm(right_middle_array, comparisons)
        comparisons = algorithm(left_middle_array, comparisons)
        left_index = right_index = arr_index = 0

        while left_index < len(left_middle_array) and right_index < len(right_middle_array):
            comparisons += 1
            if left_middle_array[left_index] > right_middle_array[right_index]:
                arr[arr_index] = right_middle_array[right_index]
                right_index += 1
            else:
                arr[arr_index] = left_middle_array[left_index]
                left_index += 1
            arr_index += 1
        while right_index < len(right_middle_array):
            arr[arr_index] = right_middle_array[right_index]
            right_index += 1
            arr_index += 1
        while left_index < len(left_middle_array):
            arr[arr_index] = left_middle_array[left_index]
            left_index += 1
            arr_index += 1
    return comparisons


def sort(arr):
    tmp_array = arr.copy()
    return algorithm(tmp_array, 0)
