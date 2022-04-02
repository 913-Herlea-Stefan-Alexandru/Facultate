"""
    The ui for our program
"""
from lecture_04.domain.board import init_board, to_str
from lecture_04.game.functions import is_game_won, is_game_draw, move_human, move_computer


def read_coordinates():
    row = int(input('x='))
    col = int(input('y='))
    return row, col


def start():
    """
    Starts the game
    :return:
    """
    board = init_board()
    is_human_turn = True

    while not is_game_won(board) and not is_game_draw(board):
        print(to_str(board))
        if is_human_turn:
            try:
                human_move = read_coordinates()
                move_human(board, *human_move)
            except ValueError as verr:
                print(str(verr))
                continue
        else:
            move_computer(board)
        is_human_turn = not is_human_turn
    print('\n'+to_str(board))
    # TODO Give a message regarding victory or loss

start()