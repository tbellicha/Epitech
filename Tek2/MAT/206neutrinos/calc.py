#!/usr/bin/env python3

import math
import sys


def std_dev(prev_std_dev, ar_mean, nb_val, input_value):
    try:
        res = math.sqrt((((pow(prev_std_dev, 2) + pow(ar_mean, 2)) * (nb_val - 1) + pow(input_value, 2)) / nb_val) - pow(((ar_mean * (nb_val - 1)) + input_value) / nb_val, 2))
    except ZeroDivisionError:
        sys.exit(84)
    return res


def ar_mean(prev_ar_mean, nb_val, input_val):
    try:
        res = ((prev_ar_mean * (nb_val - 1)) + input_val) / nb_val
    except ZeroDivisionError:
        sys.exit(84)
    return res


def ro_mean(nb_val, temp, input_value):
    try:
        res = math.sqrt((temp + pow(input_value, 2)) / nb_val)
    except ZeroDivisionError:
        sys.exit(84)
    return res


def har_mean(prev_har_mean, nb_val, input_val):
    try:
        res = nb_val / (((1 / prev_har_mean) * (nb_val - 1)) + (1 / input_val))
    except ZeroDivisionError:
        sys.exit(84)
    return res
