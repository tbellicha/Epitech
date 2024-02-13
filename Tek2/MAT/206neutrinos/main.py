#!/usr/bin/env python3
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./206neutrinos n a h sd\n")
    print("DESCRIPTION")
    print("\tn\tnumber of values")
    print("\ta\tarithmetic mean")
    print("\th\tharmonic mean")
    print("\tsd\tstandard deviation")
    return 1


def check_args_values(argv):
    try:
        for i in range(1, 5):
            if int(argv[i]) < 0:
                print("Argument " + str(i) + " is inferior to 0", file=sys.stderr)
                return False
    except ValueError:
        return False
    return True


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 5:
        print("Bad number of args, try with -h", file=sys.stderr)
        return 84
    if not check_args_values(argv):
        return 84
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == 84:
        return 84
    elif args_return == 1:
        return 0
    else:
        return process.process(argc, argv)
