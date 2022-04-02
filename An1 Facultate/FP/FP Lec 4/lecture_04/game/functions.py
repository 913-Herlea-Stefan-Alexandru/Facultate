"""
    Functions to manage the game
    - no ui
    - calls methods from board
"""


from lecture_04.domain.board import get_slot, move, init_board, is_board_full
import random

'''
    This is called the Strategy Design Pattern
'''

def is_game_draw(board):
    return is_board_full(board) and not is_game_won(board)

def is_game_won(board):
    # TODO Implement this
    for col in range(3):
        if get_slot(board, 0, col) == get_slot(board, 1, col) == get_slot(board, 1, col) != None:
            return True
    for row in range(3):
        if get_slot(board, row, 0) == get_slot(board, row, 1) == get_slot(board, row, 2) != None:
            return True
    if get_slot(board, 0, 0) == get_slot(board, 1, 1) == get_slot(board, 2, 2) != None:
        return True
    if get_slot(board, 0, 2) == get_slot(board, 1, 1) == get_slot(board, 2, 0) != None:
        return True
    return False

def move_computer_smart(board):
    """
    ...
    :return:
    """
    # TODO Make computer play smart, but valid moves
    pass


def move_computer_random(board):
    """
    ...
    :return:
    """
    # TODO Make computer play random, but valid moves
    row = random.randrange(0, 3)
    col = random.randrange(0, 3)
    while not (get_slot(board, row, col) is None):
        row = random.randrange(0, 3)
        col = random.randrange(0, 3)
    move(board, row, col, 'O')

def move_computer_simple(board):
    """
    Make the computer's next move (O)
    :param board:
    :return:
    """
    for row in range(3):
        for col in range(3):
            if get_slot(board, row, col) is None:
                # computer always plays O
                move(board, row, col, 'O')
                return
    raise ValueError("Cannot make move on a full board")

def move_computer(board):
    #move_computer_simple(board)
    move_computer_random(board)
    #move_computer_smart(board)

def move_human(board, row, col):
    """
    Make the human's move
    :param board:
    :param row:
    :param col:
    :return:
    Raise ValueError if it is an invalid move
    """
    move(board, row, col, 'X')

def test_move_computer():
    b = init_board()
    for i in range(3):
        for j in range(3):
            move_computer(b)
            assert get_slot(b, i, j) == 'O'
    assert is_board_full(b)