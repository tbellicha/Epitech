#!/usr/bin/env python3
import sys
import calc
import disp
import math


class InputError(Exception):
    pass


def check_input(input_value: str) -> float:
    try:
        value = float(input_value)
        if value < 0:
            print("Incorrect Value, try again.", file=sys.stderr)
            raise InputError
    except ValueError:
        print("Incorrect Value, try again.", file=sys.stderr)
        raise InputError
    return value


def process(argc, argv):
    nb_val = int(argv[1])
    ar_mean = int(argv[2])
    har_mean = int(argv[3])
    std_dev = int(argv[4])
    ro_mean_sq = 0

    while 1:
        try:
            input_value = input("Enter next value: ")
        except (KeyboardInterrupt, KeyError, EOFError):
            return 84
        if input_value == "END":
            return 0
        try:
            value = check_input(input_value)
        except InputError:
            sys.exit(84)
        temp = (pow(std_dev, 2) + pow(ar_mean, 2)) * nb_val
        nb_val += 1
        std_dev = calc.std_dev(std_dev, ar_mean, nb_val, value)
        ar_mean = calc.ar_mean(ar_mean, nb_val, value)
        ro_mean_sq = calc.ro_mean(nb_val, temp, value)
        har_mean = calc.har_mean(har_mean, nb_val, value)
        disp.res(nb_val, std_dev, ar_mean, ro_mean_sq, har_mean)

