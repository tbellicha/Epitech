#!/usr/bin/env python3
import sys
from contextlib import redirect_stderr, redirect_stdout
from io import StringIO

from src.command.begin import *
from src.command.start import *
from src.command.turn import *
from src.commands import *


class capture_out(redirect_stdout):
    def __init__(self):
        self.f = StringIO()
        self._new_target = self.f
        self._old_targets = []

    def __enter__(self):
        self._old_targets.append(getattr(sys, self._stream))
        setattr(sys, self._stream, self._new_target)
        return self

    def __repr__(self):
        return self.f.getvalue()


def test_start_correct():
    cmds = Commands()
    args = ["20"]

    with capture_out() as buf:
        start(cmds, args)
        output = str(buf)
    assert output == "OK\n"
    assert cmds._size_x == 20
    assert cmds._size_y == 20


def test_start_empty():
    cmds = Commands()
    args = []

    with capture_out() as buf:
        start(cmds, args)
        output = str(buf)
    assert output[:15] == "ERROR message -"


def test_start_inferior_to_5():
    cmds = Commands()
    args = ["4"]

    with capture_out() as buf:
        start(cmds, args)
        output = str(buf)
    assert output[:15] == "ERROR message -"


def test_start_not_integer():
    cmds = Commands()
    args = ["a"]

    with capture_out() as buf:
        start(cmds, args)
        output = str(buf)
    assert output[:15] == "ERROR message -"


def test_turn_empty():
    cmds = Commands()
    args = []

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_correct():
    cmds = Commands()
    args = ["4,4"]

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
        x = int(output.split(",")[0])
        y = int(output.split(",")[1])
        x_op = int(args[0].split(",")[0])
        y_op = int(args[0].split(",")[1])
    assert x < cmds._size_x
    assert y < cmds._size_y
    assert cmds._board[y][x] == 1
    assert cmds._board[y_op][x_op] == 2


def test_turn_not_in_the_map():
    cmds = Commands()
    args = ["16,4"]

    start(cmds, ["8"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_game_not_started():
    cmds = Commands()
    args = ["4,4"]

    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_3_value():
    cmds = Commands()
    args = ["4,4,1"]

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_3_args():
    cmds = Commands()
    args = ["4,4", "1"]

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_no_comma():
    cmds = Commands()
    args = ["4", "1"]

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_turn_not_integers():
    cmds = Commands()
    args = ["a,4"]

    start(cmds, ["16"])
    with capture_out() as buf:
        turn(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"


def test_begin_correct():
    cmds = Commands()
    args = []

    start(cmds, ["8"])
    with capture_out() as buf:
        begin(cmds, args)
        output = str(buf)
        x = int(output.split(",")[0])
        y = int( output.split(",")[1])
    assert x < cmds._size_x
    assert y < cmds._size_y
    assert cmds._board[y][x] == 1


def test_begin_incorrect():
    cmds = Commands()
    args = ["idk"]

    start(cmds, ["8"])
    with capture_out() as buf:
        begin(cmds, args)
        output = str(buf)
    assert output[:7] == "DEBUG -"
