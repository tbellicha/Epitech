from src.play import play
from src.stdout import printDebug


def turn(self, args):
    if len(args) != 1 or len(args[0].split(",")) != 2:
        printDebug("TURN <x,y>")
        return
    try:
        x = int(args[0].split(",")[0])
        y = int(args[0].split(",")[1])
    except ValueError:
        printDebug("TURN <x,y> (x and y must be integers)")
        return
    if not 0 <= x < self._size_x or not 0 <= y < self._size_y:
        printDebug("TURN (Coordinates not in the field of the board)")
        return
    self._board[y][x] = 2
    x, y = play(self._board)
    self._board[y][x] = 1
    print(f"{x},{y}", flush=True)
