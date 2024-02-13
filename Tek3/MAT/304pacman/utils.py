#!/usr/bin/env python3.10

EMPTY_SQUARE = '0'
WALL = '1'
GHOST = 'F'
PACMAN = 'P'

X = 0
Y = 1


def right(x: int, y: int):
    return x + 1, y


def up(x: int, y: int):
    return x, y - 1


def down(x: int, y: int):
    return x, y + 1


def left(x: int, y: int):
    return x - 1, y


DIRECTION = {"up": up, "right": right, "DOWN": down, "LEFT": left}


def get_left(map_str: list, x: int, y: int):
    return map_str[y][x - 1]


def get_right(map_str: list, x: int, y: int):
    return map_str[y][x + 1]


def get_down(map_str: list, x: int, y: int):
    return map_str[y + 1][x]


def get_up(map_str: list, x: int, y: int):
    return map_str[y - 1][x]


get_dir = {"up": get_up, "right": get_right, "DOWN": get_down, "LEFT": get_left}


def is_digit(element):
    try:
        int(element)
    except ValueError:
        return False
    else:
        return True
