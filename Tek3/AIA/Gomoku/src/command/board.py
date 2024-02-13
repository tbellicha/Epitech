from src.play import play
from src.stdout import printDebug


def board(self, args):
    if len(args) != 0:
        printDebug("BOARD")
        return
    while True:
        buffer = input()
        if buffer == "DONE":
            break
        buffer = buffer.strip("\n").split(",")
        if len(buffer) != 3:
            printDebug("BOARD (needs 3 arguments per line)")
            return
        try:
            x = int(buffer[0])
            y = int(buffer[1])
            player = int(buffer[2])
        except ValueError:
            printDebug("BOARD (x, y and player must be integers)")
            return
        if not 1 <= player <= 2:
            printDebug("BOARD (player must be 1 or 2)")
            return
        if not 0 <= x < self._size_x or not 0 <= y < self._size_y:
            printDebug("BOARD (Coordinates not in the field of the board)")
            return
        if self._board[y][x] != 0:
            printDebug("BOARD (Duplicate coordinates)")
            return
        self._board[y][x] = player
    x, y = play(self._board)
    self._board[y][x] = 1
    print(f"{x},{y}", flush=True)
