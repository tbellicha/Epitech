from src.stdout import printDebug


def begin(self, args):
    if len(args) != 0:
        printDebug("BEGIN")
        return
    x = int((self._size_x - self._size_x % 2) / 2)
    y = int((self._size_y - self._size_y % 2) / 2)
    self._board[y][x] = 1
    print(f"{x},{y}", flush=True)
