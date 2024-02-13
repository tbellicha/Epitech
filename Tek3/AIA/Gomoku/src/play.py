import random
import copy

from src.analysis import *
from src.stdout import *


value_map = [
    [4, 5, 6, 5, 4, 5, 6, 5, 4],
    [5, 3, 4, 4, 3, 4, 4, 3, 5],
    [6, 4, 2, 3, 2, 3, 2, 4, 6],
    [5, 4, 3, 1, 1, 1, 3, 4, 5],
    [4, 3, 2, 1, 0, 1, 2, 3, 4],
    [5, 4, 3, 1, 1, 1, 3, 4, 5],
    [6, 4, 2, 3, 2, 3, 2, 4, 6],
    [5, 3, 4, 4, 3, 4, 4, 3, 5],
    [4, 5, 6, 5, 4, 5, 6, 5, 4]
]


def play_random(board):
    x = random.randint(0, len(board) - 1)
    y = random.randint(0, len(board) - 1)
    while board[y][x] != 0:
        x = random.randint(0, len(board) - 1)
        y = random.randint(0, len(board) - 1)
    return x, y


def get_tab(init_board, player):
    dirs = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]
    simple_coords = []
    influence_data = []
    map_values = [[0 for x in range(len(init_board))] for y in range(len(init_board))]
    tab_nb = []
    ## We decrease the value of the cases that are close to a border
    for y in range(len(map_values)):
        for x in range(len(map_values)):
            if init_board[y][x] != ' ':
                continue
            if not 4 < y < len(map_values) - 4:
                map_values[y][x] -= 0.25
            if not 4 < x < len(map_values) - 4:
                map_values[y][x] -= 0.25
    for y in range(len(init_board)):
        for x in range(len(init_board)):
            if init_board[y][x] == ' ':
                tab_nb.clear()
                ## Check in all directions
                for i in range(len(dirs)):
                    empty = False
                    ## Browse 4 cases in the direction
                    for n in range(1, 5):
                        new_x = x + n * dirs[i][0]
                        new_y = y + n * dirs[i][1]
                        ## Check if the case is in the board
                        if 0 <= new_x < len(init_board) and 0 <= new_y < len(init_board):
                            leave = False
                            ## Check if the case is one of the player's
                            if init_board[new_y][new_x] == player:
                                for h in range(1, 6 - n):
                                    if 0 <= new_x + h * dirs[i][0] < len(init_board) and 0 <= new_y + h * dirs[i][1] < len(init_board):
                                        if init_board[new_y + h * dirs[i][1]][new_x + h * dirs[i][0]] != player and init_board[new_y + h * dirs[i][1]][new_x + h * dirs[i][0]] != ' ':
                                            ## If blocked in that direction
                                            leave = True
                                            break
                                ## Blocked in the direction, we don't add the case
                                if leave:
                                    break
                                ## Check if the found case isn't already in the tab
                                if (x, y) not in simple_coords:
                                    simple_coords.append((x, y))
                                    influence_data.append([(new_x, new_y)])
                                else:
                                    influence_data[simple_coords.index((x, y))].append((new_x, new_y))
                                val = n
                                if empty:
                                    val -= 1.5
                                map_values[y][x] += val
                                tab_nb.append(val)
                            ## If it's a case of the opponent, we stop the search in that direction
                            elif init_board[new_y][new_x] != player and init_board[new_y][new_x] != ' ':
                                break
                            elif not empty:
                                ## It's the first empty case in the direction
                                empty = True
                            elif empty:
                                ## It's the second empty case in the direction, so no more direct influence, we leave
                                break
                        ## If the case is out of the board, we leave
                        else:
                            break
                nb_three = 0
                nb_two = 0
                ## If in the same direction we have a play that has influences of 3 or 3 and 2, we add a value to the case
                if len(tab_nb) > 1:
                    for k in tab_nb:
                        if k > 2:
                            nb_three += 1
                        if k == 2:
                            nb_two += 1
                    if nb_three > 1 or (nb_three > 0 and nb_two > 0) or nb_two > 1:
                        map_values[y][x] += 4 * nb_three + 2 * nb_two
    return map_values


def play(board):
    my_urg = returnUrgent(board, 1)
    enemy_urg = returnUrgent(board, 2)
    mine = False
    if len(my_urg) > 0:
        mine = True
        most_urg = my_urg[0]
    elif len(enemy_urg) > 0:
        most_urg = enemy_urg[0]
    if my_urg:
        for i in range(len(my_urg)):
            if my_urg[i][2] > most_urg[2]:
                most_urg = my_urg[i]
            elif my_urg[i][2] == most_urg[2] and len(my_urg[i][3]) > len(most_urg[3]):
                most_urg = my_urg[i]
    if enemy_urg:
        for i in range(len(enemy_urg)):
            if enemy_urg[i][2] > most_urg[2]:
                most_urg = enemy_urg[i]
                mine = False
            elif enemy_urg[i][2] == most_urg[2] and len(enemy_urg[i][3]) > len(most_urg[3]) and not mine:
                most_urg = enemy_urg[i]
                mine = False
    if my_urg or enemy_urg:
        return most_urg[1][1], most_urg[1][0]
    board_value = copy.deepcopy(board)
    board_str = copy.deepcopy(board)
    for y in range(len(board_str)):
        for x in range(len(board_str)):
            if board_str[y][x] == 1:
                board_str[y][x] = 'O'
            elif board_str[y][x] == 2:
                board_str[y][x] = 'X'
            else:
                board_str[y][x] = ' '
    best_score = -2000
    list_coords = []
    board_value = get_tab(board_str, 'O')
    board_value_op = get_tab(board_str, 'X')
    for y in range(len(board_value)):
        for x in range(len(board_value)):
            board_value[y][x] += board_value_op[y][x]
            if board_str[y][x] == 'X' or board_str[y][x] == 'O':
                continue
            if board_value[y][x] > best_score:
                list_coords.clear()
            if board_value[y][x] >= best_score:
                list_coords.append((x, y))
                best_score = board_value[y][x]
    return list_coords[0][0], list_coords[0][1]