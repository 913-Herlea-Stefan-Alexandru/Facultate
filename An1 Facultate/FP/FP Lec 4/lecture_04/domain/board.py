"""
    Functions for managing the games board
    - exceptions!
    - unit tests!
"""

def to_str(board):
    res = ''
    for row in range(3):
        for col in range(3):
            char = get_slot(board, row, col)
            res += '_' if char is None else char
        res += '\n'
    return res

def init_board():
    """
    Init an empty board
    :return: the empty board
    """
    #Valid values for a square
    #   None - empty
    #      O -> 'O'
    #      X -> 'X'
    # a list or matrix
    board = [[(None) for i in range(3)] for j in range(3)]
    return board
    # return [None] * 9

def get_slot(board, x, y):
    return board[x][y]

def set_slot(board, x, y, char):
    board[x][y] = char

def is_board_full(board):
    """
    Check if board is full
    :param board:
    :return: True if is full, False otherwise
    """
    for row in range(3):
        for col in range(3):
            if get_slot(board, row, col) is None:
                # return false as soon as i know
                return False
    return True


def move(board, x, y, char):
    """
    Make a move!
    :param board: The board
    :param x: Coordinate [0,2]
    :param y: Coordinate [0,2]
    :param char: one of 'X' or 'O'
    :return:
    Raise ValueError if:
        - try to place on an occupied slot
        - try to place out of bounds
        - try to place an invalid char
    """
    # if not (0 <= x <= 2) or ...
    if not (x in [0, 1, 2]) or not (y in [0, 1, 2]):
        raise ValueError("Move outside the board")
    if not (char.upper() in ['X', 'O']):
        raise ValueError("Invalid character")
    if not get_slot(board, x, y) is None:
        raise ValueError("Slot already taken")
    set_slot(board, x, y, char)


def test_move():
    b = init_board()
    try:
        move(b, 2, 3, 'X')
        assert False
    except ValueError:
        assert True
    for i in range(3):
        for j in range(3):
            move(b, i, j, 'X')
    assert is_board_full(b)
    try:
        move(b, 1, 1, 'O')
        assert False
    except ValueError:
        assert True

def test_init_board():
    b = init_board()
    assert type(b) == type([])
    assert len(b) == 3
    for i in [0, 1, 2]:
        for j in [0, 1, 2]:
            assert get_slot(b, i, j) is None

def test_is_board_full():
    # TODO Complete test
    b = init_board()
    assert is_board_full(b) == False

test_move()
test_is_board_full()
test_init_board()