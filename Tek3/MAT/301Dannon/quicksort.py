#!/usr/bin/env python3.10

def sort(tmp_array):
    tmp_array = tmp_array
    length = len(tmp_array)
    comparisons = 0
    if length <= 1:
        return tmp_array, comparisons
    pivot = tmp_array[0]
    l, r, e = [], [], [pivot]
    for i in range(1, length):
        comparisons += 1
        if tmp_array[i] >= pivot:
            l.append(tmp_array[i])
        else:
            r.append(tmp_array[i])
    rl = sort(l)
    rr = sort(r)
    tmp_array = rl[0] + e + rr[0]
    comparisons += rl[1] + rr[1]
    return tmp_array, comparisons
