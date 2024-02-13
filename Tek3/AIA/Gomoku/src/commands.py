from src.command.begin import *
from src.command.board import *
from src.command.start import *
from src.command.turn import *
from src.stdout import printStdout


class Commands:
    def __init__(self):
        self._size_x = 0
        self._size_y = 0
        self._board = [[]]

    def createBoard(self, size_x, size_y):
        self._size_x = int(size_x)
        self._size_y = int(size_y)
        self._board = [[0 for x in range(self._size_x)] for y in range(self._size_y)]

    def start(self, args):
        start(self, args)

    def turn(self, args):
        turn(self, args)

    def begin(self, args):
        begin(self, args)

    def board(self, args):
        board(self, args)

    def info(self, args):
        pass

    def end(self):
        quit()

    def about(self):
        printStdout("name=\"[B5][AIA] Gomoku nathan.le-bigot@epitech.eu\", version=\"1.0\", author=\"us\", country=\"France\"")

    def debug(self, str):
        printStdout(str)
