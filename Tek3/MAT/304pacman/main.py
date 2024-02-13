#!/usr/bin/env python3
import os
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./304pacman file c1 c2\n")
    print("DESCRIPTION")
    print("\tfile\tfile describing the board, using the following characters:")
    print("\t\t'0' for an empty square,")
    print("\t\t'1' for a wall,")
    print("\t\t'F' for the ghost’s position,")
    print("\t\t'P' for Pacman’s position.")
    print("\tc1\tcharacter to display for a wall")
    print("\tc2\tcharacter to display for an empty space.")
    return 1


def check_map_chars(f):
    allowed_chars = "01FP\n"
    buff = f.read()
    if not all(ch in allowed_chars for ch in buff):
        print(f.name + ": map contains invalid characters.", file=sys.stderr)
        return -1
    if buff.count('F') != 1 or buff.count("P") != 1:
        print(f.name + ": map isn't valid (number of P and F).", file=sys.stderr)
        return -1
    return 0


def check_map(filename):
    f = open(filename)
    if check_map_chars(f):
        f.close()
        return -1
    f.close()
    return 0


def check_file_validity(filename):
    try:
        f = open(filename)
        if os.stat(filename).st_size == 0:
            print(filename + ": file is empty.", file=sys.stderr)
            f.close()
        f.close()
    except IOError:
        print(filename + ": file not found.", file=sys.stderr)
        return -1
    return 0


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 4:
        print("Bad arguments number, try with -h", file=sys.stderr)
        return -1
    if len(argv[2]) != 1 or len(argv[3]) != 1:
        print("c1 and/or c2 are not chars", file=sys.stderr)
    if argv[2] == argv[3]:
        print("c1 and c2 are the same, try with -h", file=sys.stderr)
        return -1
    if check_file_validity(argv[1]):
        return -1
    if check_map(argv[1]):
        return -1
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == -1:
        return 84
    elif args_return == 1:
        return 0
    else:
        return process.process(argc, argv)
