#!/usr/bin/env python3

import sys
import process
import argparse


def print_helper():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        print("USAGE")
        print("\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8\n")
        print("DESCRIPTION")
        print("\tOi\tsize of the observed class")
        sys.exit(0)


def parse_args():
    try:
        args = argparse.ArgumentParser(description='208Dowels', usage=print_helper())
        args.add_argument("O1", type=int)
        args.add_argument("O2", type=int)
        args.add_argument("O3", type=int)
        args.add_argument("O4", type=int)
        args.add_argument("O5", type=int)
        args.add_argument("O6", type=int)
        args.add_argument("O7", type=int)
        args.add_argument("O8", type=int)
        args.add_argument("O9", type=int)
        Oargs = args.parse_args()
        tab = [Oargs.O1, Oargs.O2, Oargs.O3, Oargs.O4, Oargs.O5, Oargs.O6, Oargs.O7, Oargs.O8, Oargs.O9]
        tot_sum = 0
        for arg in tab:
            tot_sum += arg
            if arg < 0:
                print("Arguments must be positive")
                raise ValueError
        if tot_sum != 100:
            print("Sum of arguments must be 100, actually it's %d" % tot_sum)
            raise ValueError
        return tab
    except:
        sys.exit(84)


def check_args_values(argv):
    tot_sum = 0
    try:
        for i in range(1, 10):
            if int(argv[i]) < 0:
                print("Argument " + str(i) + " is inferior to 0", file=sys.stderr)
                return False
            tot_sum += int(argv[i])
    except ValueError:
        return False
    if tot_sum != 100:
        print(tot_sum)
        print("You must pass arguments equal to 100", file=sys.stderr)
        return False
    return True


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 10:
        print("Bad number of args, try with -h", file=sys.stderr)
        return 84
    if not check_args_values(argv):
        return 84
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == 84:
        return 84
    else:
        args_return = parse_args()
        if args_return == 84:
            return 84
        elif args_return == 1:
            return 0
        else:
            return process.process()
