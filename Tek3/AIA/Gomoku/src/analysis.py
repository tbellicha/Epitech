#!/usr/bin/env python3
from enum import Enum


class Direction(Enum):
    HOR = 0
    VER = 1
    DIAG = 2
    RDIAG = 3

def check3tile(board, player):
    tiles = []
    for i in range(len(board)):
        for j in range(len(board)):
            if (board[i][j] != 0):
                continue
            if (j <= len(board) - 5 and board[i][j+1] == board[i][j+2] == board[i][j+3] == player and (board[i][j+4] == player or board[i][j+4] == 0)) \
            or (j >= 4 and board[i][j-1] == board[i][j-2] == board[i][j-3] == player and (board[i][j-4] == player or board[i][j-4] == 0)) \
            or (j <= len(board) - 4 and j >= 2 and board[i][j+1] == board[i][j+2] == board[i][j-1] == player) \
            or (j <= len(board) - 3 and j >= 3 and board[i][j+1] == board[i][j-1] == board[i][j-2] == player):
                tiles.append((i,j, Direction.HOR))
            if (i <= len(board) - 5 and board[i+1][j] == board[i+2][j] == board[i+3][j] == player and (board[i+4][j] == player or board[i+4][j] == 0)) \
            or (i >= 4 and board[i-1][j] == board[i-2][j] == board[i-3][j] == player and (board[i-4][j] == player or board[i-4][j] == 0)) \
            or (i <= len(board) - 4 and i >= 2 and board[i+1][j] == board[i+2][j] == board[i-1][j] == player) \
            or (i <= len(board) - 3 and i >= 3 and board[i+1][j] == board[i-1][j] == board[i-2][j] == player):
                tiles.append((i,j, Direction.VER))
            if (i <= len(board) - 5 and j <= len(board) - 5 and board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3] == player and (board[i+4][j+4] == player or board[i+4][j+4] == 0)) \
            or (i >= 4 and j >= 4 and board[i-1][j-1] == board[i-2][j-2] == board[i-3][j-3] == player and (board[i-4][j-4] == player or board[i-4][j-4] == 0)) \
            or (i <= len(board) - 4 and i >= 2 and j <= len(board) - 4 and j >= 2 and board[i+1][j+1] == board[i+2][j+2] == board[i-1][j-1] == player) \
            or (i <= len(board) - 3 and i >= 3 and j <= len(board) - 3 and j >= 3 and board[i+1][j+1] == board[i-1][j-1] == board[i-2][j-2] == player):
                tiles.append((i,j, Direction.DIAG))
            if (i <= len(board) - 5 and j >= 4 and board[i+1][j-1] == board[i+2][j-2] == board[i+3][j-3] == player and (board[i+4][j-4] == player or board[i+4][j-4] == 0)) \
            or (i >= 4 and j <= len(board) - 5 and board[i-1][j+1] == board[i-2][j+2] == board[i-3][j+3] == player and (board[i-4][j+4] == player or board[i-4][j+4] == 0)) \
            or (i <= len(board) - 4 and i >= 2 and j >= 4 and j <= len(board) - 3 and board[i+1][j-1] == board[i+2][j-2] == board[i-1][j+1] == player) \
            or (i <= len(board) - 3 and i >= 3 and j >= 3 and j <= len(board) - 4 and board[i+1][j-1] == board[i-1][j+1] == board[i-2][j+2] == player):
                tiles.append((i,j, Direction.RDIAG))
    return tiles

def countVerTiles(board, posx, posy, size, target):
    count = 0
    for i in range(posx, posx + size):
        if (i >= len(board) or i < 0):
            return -1
        if (board[i][posy] == target):
            count += 1
        if (board[i][posy] != 0 and board[i][posy] != target):
            return 0
    return count

def countHorTiles(board, posx, posy, size, target):
    count = 0
    for i in range(posy, posy + size):
        if (i >= len(board) or i < 0):
            return -1
        if (board[posx][i] == target):
            count += 1
        if (board[posx][i] != 0 and board[posx][i] != target):
            return 0
    return count

def countDiaTiles(board, posx, posy, size, target):
    count = 0
    for i in range(size):
        if (posx + i >= len(board) or posx + i < 0 or posy + i >= len(board) or posy + i < 0):
            return -1
        if (board[posx + i][posy + i] == target):
            count += 1
        if (board[posx + i][posy + i] != 0 and board[posx + i][posy + i] != target):
            return 0
    return count

def countRDiagTiles(board, posx, posy, size, target):
    count = 0
    for i in range(size):
        if (posx + i >= len(board) or posx + i < 0 or posy - i >= len(board) or posy - i < 0):
            return -1
        if (board[posx + i][posy - i] == target):
            count += 1
        if (board[posx + i][posy - i] != 0 and board[posx + i][posy - i] != target):
            return 0
    return count

# returnUrgent returns the urgent tiles for the ai to play
# The list is composed of two tuples and two variables
# The first tuple is the starting position of the 5 connection
# The second tuple is the tile to play
# The first variable is the priority of the connection
# The second variable is the direction of the 5 connection

def check2Line(board, player, tiles):
    urgent = []
    for x in range(len(board)):
        for y in range(len(board)):
            if (board[x][y] != 0):
                continue
            if (x, y) in tiles:
                continue
            tilePos = (x, y)
            cur = 0
            directions = []
            high = 0
            if (y <= len(board) - 2 and board[x][y+1] == player or y >= 1 and board[x][y-1] == player):
                highest = countHorTiles(board, x, y, 5, player)
                for i in range(-4, 0):
                    cur = countHorTiles(board, x, y+i, 5, player)
                    if (cur > highest):
                        highest = cur
                        tilePos = (x, y+i)
                if (highest >= 2):
                    directions.append(Direction.HOR)
                    if (high < highest):
                        high = highest
            if (x <= len(board) - 2 and board[x+1][y] == player or x >= 1 and board[x-1][y] == player):
                highest = countVerTiles(board, x, y, 5, player)
                for i in range(-4, 0):
                    cur = countVerTiles(board, x+i, y, 5, player)
                    if (cur > highest):
                        highest = cur
                        tilePos = (x+i, y)
                if (highest >= 2):
                    directions.append(Direction.VER)
                    if (high < highest):
                        high = highest
            if (x <= len(board) - 2 and y <= len(board) - 2 and board[x+1][y+1] == player or x >= 1 and y >= 1 and board[x-1][y-1] == player):
                highest = countDiaTiles(board, x, y, 5, player)
                for i in range(-4, 0):
                    cur = countDiaTiles(board, x+i, y+i, 5, player)
                    if (cur > highest):
                        highest = cur
                        tilePos = (x+i, y+i)
                if (highest >= 2):
                    directions.append(Direction.DIAG)
                    if (high < highest):
                        high = highest
            if (x <= len(board) - 2 and y >= 1 and board[x+1][y-1] == player or x >= 1 and y <= len(board) - 2 and board[x-1][y+1] == player):
                highest = countRDiagTiles(board, x, y, 5, player)
                for i in range(-4, 0):
                    cur = countRDiagTiles(board, x+i, y-i, 5, player)
                    if (cur > highest):
                        highest = cur
                        tilePos = (x+i, y-i)
                if (highest >= 2):
                    directions.append(Direction.RDIAG)
                    if (high < highest):
                        high = highest
            if (len(directions) > 1):
                urgent.append((tilePos, (x, y), 2, directions))
    return urgent

def returnUrgent(board, player):
    urgent = []
    tiles = check3tile(board, player)
    for i in range(len(tiles)):
        tilePos = (tiles[i][0], tiles[i][1])
        x = tiles[i][0]
        y = tiles[i][1]
        cur = 0
        directions = []
        high = 0
        highest = countHorTiles(board, x, y, 5, player)
        for i in range(-4, 0):
            cur = countHorTiles(board, x, y+i, 5, player)
            if (cur > highest):
                highest = cur
                tilePos = (x, y+i)
        if (highest > 2):
            directions.append(Direction.HOR)
            if (high < highest):
                high = highest
        highest = countVerTiles(board, x, y, 5, player)
        for i in range(-4, 0):
            cur = countVerTiles(board, x+i, y, 5, player)
            if (cur > highest):
                highest = cur
                tilePos = (x+i, y)
        if (highest > 2):
            directions.append(Direction.VER)
            if (high < highest):
                high = highest
        highest = countDiaTiles(board, x, y, 5, player)
        for i in range(-4, 0):
            cur = countDiaTiles(board, x+i, y+i, 5, player)
            if (cur > highest):
                highest = cur
                tilePos = (x+i, y+i)
        if (highest > 2):
            directions.append(Direction.DIAG)
            if (high < highest):
                high = highest
        highest = countRDiagTiles(board, x, y, 5, player)
        for i in range(-4, 0):
            cur = countRDiagTiles(board, x+i, y-i, 5, player)
            if (cur > highest):
                highest = cur
                tilePos = (x+i, y-i)
        if (highest > 2):
            directions.append(Direction.RDIAG)
            if (high < highest):
                high = highest
        if (len(directions) > 0):
            urgent.append((tilePos, (x, y), high, directions))
    return urgent + check2Line(board, player, tiles)