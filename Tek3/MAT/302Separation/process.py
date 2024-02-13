#!/usr/bin/env python3.10
import sys
import os
import time


def get_relation_list(file, unique_list):
    file_relation_list = []
    for i in file:
        if i.find(' is friends with ') == -1:
            print("Bad file format", file=sys.stderr)
            return 84
        i = i.replace('\n', '')
        file_relation_list.append(i.split(' is friends with '))
    relation_list = []
    left_right = 1
    for curr_relation in file_relation_list:
        left_right = 1
        for curr_person in curr_relation:
            if curr_person not in unique_list:
                unique_list.append(curr_person)
                relation_list.append([curr_relation[left_right]])
            else:
                relation_list[unique_list.index(curr_person)].append(curr_relation[left_right])
            left_right -= 1
    return relation_list


def bubble_sort(unique_list, relation_list):
    for i in range(len(unique_list)):
        for j in range(len(unique_list) - 1):
            if unique_list[j] > unique_list[j + 1]:
                unique_list[j], unique_list[j + 1] = unique_list[j + 1], unique_list[j]
                relation_list[j], relation_list[j + 1] = relation_list[j + 1], relation_list[j]
    return unique_list


def compute_path_length(relation_list, unique_list, number):
    try:
        n = int(number)
    except ValueError:
        print("Bad arguments number, try with -h", file=sys.stderr)
        return 84
    if (n < 0):
        print("Bad arguments number, try with -h", file=sys.stderr)
        return 84
    bubble_sort(unique_list, relation_list)
    for i in unique_list:
        print(i)
    print('')
    tempo_list = relation_list.copy()
    for p1 in unique_list:
        for p2 in unique_list:
            if unique_list.index(p2) == len(unique_list) - 1:
                print(int(p2 in relation_list[unique_list.index(p1)]), end='')
            else:
                print(int(p2 in relation_list[unique_list.index(p1)]), end=' ')
        print('')
    print('')
    for p1 in unique_list:
        for p2 in unique_list:
            depth = get_separation_degree(tempo_list, unique_list, p1, p2)
            if depth > int(number) or depth == -1:
                depth = 0
            if unique_list.index(p2) == len(unique_list) - 1:
                print(depth)
            else:
                print(str(depth), end=' ')
            relation_list = tempo_list.copy()
    return 0


def get_separation_degree(relation_list, unique_list, p1, p2):
    if p1 not in unique_list or p2 not in unique_list:
        return -1
    i = 0
    curr_relation = relation_list[unique_list.index(p1)].copy()
    checked_list = p1
    while 1:
        if p2 in checked_list:
            return i
        new_relation = []
        for curr_person in curr_relation:
            if curr_person not in checked_list:
                new_relation.extend(relation_list[unique_list.index(curr_person)])
                checked_list += curr_person
        if new_relation == []:
            return -1
        curr_relation.extend(new_relation.copy())
        i += 1


def process(argc, argv):
    try:
        f = open(argv[1])
    except FileNotFoundError:
        print("File doesn't exists", file=sys.stderr)
        return 84
    if os.path.getsize(argv[1]) == 0:
        print("File is empty", file=sys.stderr)
        return 84
    unique_list = []
    relation_list = get_relation_list(f, unique_list)
    if relation_list == 84:
        ret = 84
    elif argc == 3:
        ret = compute_path_length(relation_list, unique_list, argv[2])
    elif argc == 4:
        ret = 0
        print("Degree of separation between " + argv[2] + " and " + argv[3] + ": " + str(get_separation_degree(relation_list, unique_list, argv[2], argv[3])))
    f.close()
    return ret
