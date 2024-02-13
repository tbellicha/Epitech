#!/usr/bin/env python3.10

class Position:
    def __init__(self, chars: str):
        self._x = -1
        self._y = -1
        self._c = chars

    def get_pos_in_list(self, my_list: list, elem_type: str, token: str):
        found = False
        for i in range(len(my_list)):
            for j in range(len(my_list[i])):
                if my_list[i][j] == token and found:
                    print("Too many {}s.".format(elem_type))
                    exit(84)
                elif my_list[i][j] == token:
                    self._x = j
                    self._y = i
                    found = True

    @property
    def x(self):
        return self._x

    @property
    def c(self):
        return self._c

    @property
    def y(self):
        return self._y
