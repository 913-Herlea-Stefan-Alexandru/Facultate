"""
Assemble the program and start the user interface here
"""

from src.ui.console import *
from src.functions.functions import split_command, test_init, create_calc

def start_command_ui():
    '''
    Handles user commands and all of the functionalities of the program
    :return: -
    '''
    is_running = True
    command_dict = {'add': add_score_command_ui, 'insert': insert_score_command_ui, 'list': print_list_command_ui, 'replace': replace_score_command_ui, 'remove': remove_score_command_ui, 'avg': average_command_ui, 'min': minimum_command_ui, 'top': top_command_ui, 'undo': undo_command_ui}
    score_list = []
    test_init(score_list)
    calc = create_calc(score_list)
    print('Type \'help\' for a list of commands')
    while is_running:
        command = input("command>> ")
        command_word, command_params = split_command(command)
        if command_word in command_dict:
            try:
                command_dict[command_word](calc, command_params)
            except ValueError as ve:
                print(str(ve))
        elif command_word == 'exit':
            is_running = False
        elif command_word == 'help':
            print_menu()
        else:
            print("Wrong command")


start_command_ui()