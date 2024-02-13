#!/usr/bin/env python3
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./303make makefile [file]\n")
    print("DESCRIPTION")
    print("\tmakefile\tname of the makefile")
    print("\tfile\tname of a recently modified file")
    return 1


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc < 2 or argc > 3:
        print("Bad arguments number, try with -h", file=sys.stderr)
        return -1
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == -1:
        return 84
    elif args_return == 1:
        return 0
    else:
        return process.process(argv[1:])
