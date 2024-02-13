#!/usr/bin/env python3
import sys

from src.commands import Commands
from src.stdout import printDebug


def main() -> int:
    cmds = Commands()
    while True:
        try:
            buffer = input()
        except KeyboardInterrupt:
            break
        except EOFError:
            return 0
        buffer = buffer.strip("\n").split(" ")
        command_input = buffer[0]
        if len(buffer) > 1:
            args_input = buffer[1:]
        else:
            args_input = []
        if (command_input == "START" or command_input == "RESTART"):
            cmds.start(args_input)
        elif (command_input == "TURN"):
            cmds.turn(args_input)
        elif (command_input == "BEGIN"):
            cmds.begin(args_input)
        elif (command_input == "BOARD"):
            cmds.board(args_input)
        elif (command_input == "INFO"):
            cmds.info(args_input)
        elif (command_input == "ABOUT"):
            cmds.about()
        elif (command_input == "END"):
            cmds.end()
        elif (command_input == "DEBUG"):
            cmds.debug(buffer[1])
        else:
            printDebug("Unknown command : " + command_input)
    return 0

if __name__ == '__main__':
    sys.exit(main())
