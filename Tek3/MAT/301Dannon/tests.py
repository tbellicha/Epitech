#!/usr/bin/env python3

import bubble_sort
import merge_sort
import quicksort
import selection_sort
import insertion_sort


def run_tests():
    test_bubble_sort()
    test_merge_sort()
    # test_quick_sort()
    test_selection_sort()
    test_insertion_sort()


def test_bubble_sort():
    large_arr = [-564, 1340, 42, 129, 858, 1491, 1508, 246, -1281,
                 655, 1506, 306, 290, -768, 116, 765, -48, -512, 2598, 42, 2339]
    expected_large_result = 210
    small_arr = [3.3, 5, 9.89, -6]
    expected_small_result = 6
    large_result = bubble_sort.sort(large_arr)
    small_result = bubble_sort.sort(small_arr)
    assert large_result == expected_large_result, small_result == expected_small_result


def test_merge_sort():
    large_arr = [-564, 1340, 42, 129, 858, 1491, 1508, 246, -1281,
                 655, 1506, 306, 290, -768, 116, 765, -48, -512, 2598, 42, 2339]
    expected_large_result = 67
    small_arr = [3.3, 5, 9.89, -6]
    expected_small_result = 5
    large_result = merge_sort.sort(large_arr)
    small_result = merge_sort.sort(small_arr)
    assert large_result == expected_large_result, small_result == expected_small_result


def test_quick_sort():
    large_arr = [-564, 1340, 42, 129, 858, 1491, 1508, 246, -1281,
                 655, 1506, 306, 290, -768, 116, 765, -48, -512, 2598, 42, 2339]
    expected_large_result = 80
    small_arr = [3.3, 5, 9.89, -6]
    expected_small_result = 4
    arr, large_result = quicksort.sort(large_arr)
    arr, small_result = quicksort.sort(small_arr)
    assert large_result == expected_large_result, small_result == expected_small_result


def test_selection_sort():
    large_arr = [-564, 1340, 42, 129, 858, 1491, 1508, 246, -1281,
                 655, 1506, 306, 290, -768, 116, 765, -48, -512, 2598, 42, 2339]
    expected_large_result = 210
    small_arr = [3.3, 5, 9.89, -6]
    expected_small_result = 6
    large_result = selection_sort.sort(large_arr)
    small_result = selection_sort.sort(small_arr)
    assert large_result == expected_large_result, small_result == expected_small_result


def test_insertion_sort():
    large_arr = [-564, 1340, 42, 129, 858, 1491, 1508, 246, -1281,
                 655, 1506, 306, 290, -768, 116, 765, -48, -512, 2598, 42, 2339]
    expected_large_result = 125
    small_arr = [3.3, 5, 9.89, -6]
    expected_small_result = 4
    large_result = insertion_sort.sort(large_arr)
    small_result = insertion_sort.sort(small_arr)
    assert large_result == expected_large_result, small_result == expected_small_result
