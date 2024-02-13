#!/usr/bin/env python3
import sys

import process


def print_helper():
    print("USAGE")
    print("\t./309pollution n file x y\n")
    print("DESCRIPTION")
    print("\tn\tnumber of points on the grid axis")
    print("\tfile\tcsv file containing the data points x;y;p")
    print("\tx\tabscissa of the point whose pollution level we want to know")
    print("\ty\tordinate of the point whose pollution level we want to know")
    return 1


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 5:
        print("Bad arguments number, try with -h", file=sys.stderr)
        return -1
    try:
        x = int(argv[1])
        if x < 0:
            raise ValueError
    except ValueError:
        return -1
    for arg in argv[3:]:
        try:
            x = float(arg)
            if x < 0 or x > (int(argv[1]) - 1):
                raise ValueError
        except ValueError:
            return -1
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == -1:
        return 84
    elif args_return == 1:
        return 0
    return process.process(argv)
