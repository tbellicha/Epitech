#!/usr/bin/env python3

import sys
import os
from Item import Item


def read_line(line):
    all_files = set(filter(lambda x: x, [e.strip() for e in line.replace(":", " ").split()]))
    return all_files


def parse_file(file_name):
    elements = []
    files = set()
    gradients = []
    if not os.path.exists(file_name):
        sys.exit(84)
    if os.path.getsize(file_name) == 0:
        sys.exit(84)
    f = open(file_name, "r")
    for line in f.readlines():
        line = line.strip()
        if not line:
            continue
        if ":" in line:
            files = files.union(read_line(line))
            elements.append(Item(line))
        else:
            elements[-1].gradation = line
            gradients.append(line.split())
    f.close()
    for element in elements:
        curr_left = str(element).split()[0][:-1]
        if elements.count(curr_left) > 1:
            sys.exit(84)
    return elements, list(files), gradients


def init_array(elements, files):
    array = []
    for file in files:
        if file not in elements:
            array.append([0 for _ in range(0, len(files))])
        else:
            elem = elements[elements.index(file)]
            array.append([elem.is_dependence(f) for f in files])
    return array


def get_result(i, array, files):
    for j, res in enumerate(files):
        if array[j][i] == 1:
            print(" -> " + files[j], end="")
            get_result(j, array, files)
            return


def print_result(array, elements, files):
    for i in range(len(array)):
        print("[", end="")
        for k in range(len(array[i])):
            if k == len(array[i]) - 1:
                print(array[k][i], end="]")
            else:
                print(array[k][i], end=" ")
        print("")
    print("")
    for i, file in enumerate(files):
        for j, res in enumerate(files):
            if array[j][i] == 1:
                print(files[i], end=" -> ")
                print(files[j], end="")
                get_result(j, array, files)
                print()


def get_gradation(file, elements):
    to_print = []
    for element in elements:
        if element == file or element.is_dependence(file):
            to_print.append(element.gradation)
    print("\n".join(sorted(to_print)))


def find_gradations(i, array, files, elems):
    to_ret = set()
    for j, res in enumerate(files):
        if array[j][i] == 1:
            get_gradation(files[j], elems)
            find_gradations(j, array, files, elems)
            return
    return to_ret


def print_gradation(array, file, files, elems):
    i = 0
    try:
        i = files.index(file)
    except ValueError:
        sys.exit(84)
    for j, res in enumerate(files):
        if array[j][i] == 1:
            get_gradation(files[i], elems)
            find_gradations(j, array, files, elems)
            break


def process(args):
    if len(args) == 1:
        elements, files, _ = parse_file(args[0])
        files.sort()
        array = init_array(elements, files)
        print_result(array, elements, files)
    elif len(args) == 2:
        elems, files, gradations = parse_file(args[0])
        files.sort()
        array = init_array(elems, files)
        print_gradation(array, args[1], files, elems)
    else:
        return 84
    return 0
