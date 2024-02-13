#!/usr/bin/env python3.10

from Position import Position
from utils import *


class Algo:
    def __init__(self, c1: str, c2: str):
        self._file = None
        self._output_map = None
        self._c1 = c1
        self._c2 = c2
        self._ghost = Position('F')
        self._pacman = Position('P')

    def get_map_from_file(self, filename: str):
        pac_map = []
        file = open(filename)
        buffer = file.readlines()
        for line in buffer:
            line = line.replace('\n', '')
            pac_map.append(line)
        file.close()
        return pac_map

    def create_output(self, pac_map: list):
        output_map = []
        for i in range(len(pac_map)):
            tmp_map = []
            for j in range(len(pac_map[i])):
                if pac_map[i][j] == EMPTY_SQUARE:
                    tmp_map.append(self._c2)
                elif pac_map[i][j] == WALL:
                    tmp_map.append(self._c1)
                else:
                    tmp_map.append(pac_map[i][j])
            output_map.append(tmp_map)
        return output_map

    def print_output(self, output_map: list):
        for map_line in output_map:
            for map_case in map_line:
                if is_digit(map_case):
                    map_case = int(map_case) % 10
                print(map_case, end='')
            print()

    def setup_elements(self, filename: str):
        pac_map = self.get_map_from_file(filename)
        self._output_map = self.create_output(pac_map)
        if len(pac_map) < 3:
            print("Wrong map format.")
            exit(84)
        self._ghost.get_pos_in_list(pac_map, "ghost", self._ghost.c)
        self._pacman.get_pos_in_list(pac_map, "pacman", self._pacman.c)

        return pac_map

    def compute_dijkstra(self, pac_map: list, mini: int, x: int, y: int):
        checked_cells = []

        def is_valid_cell(x_cell: int, y_cell: int):
            if y_cell < 0 or y_cell >= len(self._output_map):
                return False
            if x_cell < 0 or x_cell >= len(self._output_map[y_cell]):
                return False
            return True

        def compute_direction(pac_map_dir: list, direction_dir: str, mini_dir: int, x_dir: int, y_dir: int):

            next_direction = DIRECTION[direction_dir](x_dir, y_dir)
            if is_valid_cell(next_direction[X], next_direction[Y]):
                next_char_from_input = get_dir[direction_dir](pac_map_dir, x_dir, y_dir)
                next_char_from_output = get_dir[direction_dir](self._output_map, x_dir, y_dir)
                if next_char_from_input == self._pacman.c:
                    return True
                if next_char_from_output == self._c2:
                    self._output_map[next_direction[Y]][next_direction[X]] = mini_dir + 1
                    checked_cells.append([next_direction[X], next_direction[Y],
                                          self._output_map[next_direction[Y]][next_direction[X]]])
            return False

        for direction in DIRECTION:
            if compute_direction(pac_map, direction, mini, x, y):
                return True

        for case in checked_cells:
            for direction in DIRECTION:
                if compute_direction(pac_map, direction, case[2], case[X], case[Y]):
                    return True

    def run(self, filename: str):
        pac_map = self.setup_elements(filename)
        self.compute_dijkstra(pac_map, 0, self._ghost.x, self._ghost.y)
        self.print_output(self._output_map)
