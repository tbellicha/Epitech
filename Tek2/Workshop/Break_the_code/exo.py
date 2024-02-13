#!/usr/bin/env python3

from geopy.geocoders import Nominatim

one_degrees = 31
one_min = 15
one_sec = 00
two_degrees = 136
two_min = 42
two_sec = 00

if __name__ == '__main__':
    one_degrees = 31
    one_min = 15
    one_sec = 00
    two_degrees = 136
    two_min = 42
    two_sec = 00
    file = 'enigmes-candidats-protected/nautilus.txt'
    file1 = open(file, 'r')
    Lines = file1.readlines()

    Lines = Lines[2:]
    for line in Lines:
        i_space = line.find(' ')
        xxxx = line[:i_space - 1]
        NS = line[i_space - 1]
        yyyy = line[i_space + 1:]
        if not yyyy[:len(yyyy) - 1].isdigit():
            yyyy = yyyy[:len(yyyy) - 2]
            EW = line[len(line) - 2]
        else:
            yyyy = yyyy[:len(yyyy) - 1]
            EW = line[len(line) - 1]
        xxxx = int(xxxx)
        yyyy = int(yyyy)
        if NS == 'N':
            while xxxx > 0:
                if xxxx >= 3600:
                    one_degrees += 1
                    xxxx -= 3600
                elif xxxx >= 60:
                    one_min += 1
                    xxxx -= 60
                elif xxxx >= 1:
                    one_sec += 1
                    xxxx -= 1
        elif NS == 'S':
            while xxxx > 0:
                if xxxx >= 3600:
                    one_degrees -= 1
                    xxxx -= 3600
                elif xxxx >= 60:
                    one_min -= 1
                    xxxx -= 60
                elif xxxx >= 1:
                    one_sec -= 1
                    xxxx -= 1
        if EW == 'W':
            while yyyy > 0:
                if yyyy >= 3600:
                    two_degrees -= 1
                    yyyy -= 3600
                elif yyyy >= 60:
                    two_min -= 1
                    if two_min < 0:
                        two_degrees -= 1
                        two_min = 59
                    yyyy -= 60
                elif yyyy >= 1:
                    two_sec -= 1
                    if two_sec < 0:
                        two_min -= 1
                        two_sec = 59
                    yyyy -= 1
        elif EW == 'E':
            while yyyy > 0:
                if yyyy >= 3600:
                    two_degrees += 1
                    yyyy -= 3600
                elif yyyy >= 60:
                    two_min += 1
                    yyyy -= 60
                elif yyyy >= 1:
                    two_sec += 1
                    yyyy -= 1

    while one_sec >= 60:
        one_min += 1
        one_sec -= 60
    while one_min >= 60:
        one_degrees += 1
        one_min -= 60

    while two_sec >= 60:
        two_min += 1
        two_sec -= 60
    while two_min >= 60:
        two_degrees += 1
        two_min -= 60
    print(one_degrees, one_min, one_sec)
    print(two_degrees, two_min, two_sec)
    res = one_degrees + one_min / 60 + one_sec / 3600
    res2 = two_degrees + two_min / 60 + two_sec / 3600
    print(res, res2)

