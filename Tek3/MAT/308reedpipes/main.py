#!/usr/bin/env python3
import sys

import process


def print_helper():
    print("USAGE")
    print("\t./308reedpipes r0 r5 r10 r15 r20 n\n")
    print("DESCRIPTION")
    print("\tr0\tradius (in cm) of pipe at the 0cm abscissa")
    print("\tr5\tradius (in cm) of pipe at the 5cm abscissa")
    print("\tr10\tradius (in cm) of pipe at the 10cm abscissa")
    print("\tr15\tradius (in cm) of pipe at the 15cm abscissa")
    print("\tr20\tradius (in cm) of pipe at the 20cm abscissa")
    print("\tn\tnumber of points needed to display the radius")
    return 1


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 7:
        print("Bad arguments number, try with -h", file=sys.stderr)
        return -1
    for arg in argv[1:-1]:
        try:
            x = float(arg)
            if x <= 0:
                raise ValueError
        except ValueError:
            return -1
    try:
        x = int(argv[-1])
        if x < 0:
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
