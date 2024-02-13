from src.stdout import printStdout


def start(self, args):
    try:
        if len(args) != 1:
            raise ValueError
        try:
            size = int(args[0])
            if size < 5:
                raise ValueError
        except ValueError:
            printStdout("ERROR message - START <size> (size must be an integer superior to 5)")
            return
        self.createBoard(args[0], args[0])
    except ValueError:
        printStdout("ERROR message - START <size>")
        return
    printStdout("OK")
