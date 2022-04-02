"""
This is the user interface module. These functions call functions from the domain and functions module.
"""

from src.functions.functions import add_score, insert_score, average_score, sort_list_by_criteria, list_equal, list_greater, list_smaller, replace_score, remove_score_param, remove_score_interval, score_to_string, avg_of_avg, minimum_avg, remove_equal, remove_greater, remove_smaller, is_int, undo, add_to_last_op, get_list, get_last_op, set_list
from src.domain.entity import get_p1, get_p2, get_p3

def print_menu():
    print('(A) Add the result of a new participant')
    print('\tadd <P1 score> <P2 score> <P3 score> - adds the given score to the list')
    print('\tinsert <P1 score> <P2 score> <P3 score> at <position> - adds the given score at the given position in the list')
    print('(B) Modify scores')
    print('\tremove <position> - sets the score values of the given student to 0')
    print('\tremove <start position> to <end position> - sets the score values of the students in the given interval to 0')
    print('\treplace <position> <P1 | P2 | P3> with <new score> - replaces the given score of the given student with the new given score')
    print('(C) Display participants whose score has different properties')
    print('\tlist - prints the list')
    print('\tlist sorted - prints the list sorted decreasing by the average scores')
    print('\tlist [ < | = | > ] <score> - prints the scores with the average scores with the given condition')
    print('(D) Obtain different characteristics of participants')
    print('\tavg <start position> to <end position> - display the average of the average scores for participants between given positions')
    print('\tmin <start position> to <end position> - display the lowest average score of the participants between given positions')
    print('(E) Establish the podium')
    print('\ttop <number> - displays the given number of participants having the highest average scores, sorted decreasing by the average scores')
    print('\ttop <number> <P1 | P2 | P3> - displays the given number of participants having the highest scores at the given problem, sorted descending by that score')
    print('\tremove [ < | = | > ] <score> - sets the score values of the students with the given condition for the average score to 0')
    print('(F) Undo')
    print('\tundo – the last operation that modified program data is reversed')
    print('\tundo <number> - reverses the program data the number of times given by the user')
    print('help - list of commands')
    print('exit - exits the program')

def print_list(score_list):
    for index in range(len(score_list)):
        print((str(index) + '. ').ljust(4) + score_to_string(score_list[index]))

def add_score_command_ui(calc, params):
    scores = params.split(' ')
    if params == '' or len(scores) != 3:
        raise ValueError("Missing Parameters")
    p1 = scores[0].strip()
    p2 = scores[1].strip()
    p3 = scores[2].strip()
    score_list = get_list(calc)
    last_op = get_last_op(calc)
    add_to_last_op(score_list, last_op)
    add_score(score_list, p1, p2, p3, last_op)

def insert_score_command_ui(calc, params):
    tokens = params.split(' ')
    if len(tokens) != 5 or tokens[3].strip() != 'at':
        raise ValueError("Wrong parameters")
    p1 = tokens[0]
    p2 = tokens[1]
    p3 = tokens[2]
    index = tokens[4]
    score_list = get_list(calc)
    last_op = get_last_op(calc)
    add_to_last_op(score_list, last_op)
    insert_score(score_list, p1, p2, p3, index, last_op)

def print_list_command_ui(calc, params):
    score_list = get_list(calc)
    if params == '':
        print_list(score_list)
    elif params.lower() == 'sorted':
        copy_list = score_list.copy()
        rev = True
        crit = average_score
        sort_list_by_criteria(copy_list, rev, crit)
        print_list(copy_list)
    else:
        tokens = params.split(' ', 1)
        sign_dict = {'>': list_greater, '<': list_smaller, '=': list_equal}
        if tokens[0].strip() not in sign_dict or not is_int(tokens[1].strip()):
            raise ValueError("Wrong parameters")
        sign = tokens[0].strip()
        comp = int(tokens[1].strip())
        print_list(sign_dict[sign](score_list, comp))

def replace_score_command_ui(calc, params):
    tokens = params.split(' ')
    if len(tokens) != 4 or tokens[2].lower().strip() != 'with':
        raise ValueError("Wrong parameters")
    student = tokens[0].strip()
    problem = tokens[1].strip()
    new_score = tokens[3].strip()
    score_list = get_list(calc)
    last_op = get_last_op(calc)
    add_to_last_op(score_list, last_op)
    replace_score(score_list, student, problem, new_score, last_op)

def remove_score_command_ui(calc, params):
    score_list = get_list(calc)
    last_op = get_last_op(calc)
    add_to_last_op(score_list, last_op)
    tokens = params.split(' ')
    if len(tokens) == 1:
        remove_score_param(score_list, params, last_op)
    elif params == '':
        last_op.pop()
        raise ValueError("Please enter parameters")
    elif len(tokens) == 3:
        if tokens[1].strip().lower() != 'to':
            last_op.pop()
            raise ValueError("Wrong parameters")
        poz1 = tokens[0].strip()
        poz2 = tokens[2].strip()
        remove_score_interval(score_list, poz1, poz2, last_op)
    else:
        sign_dict = {'>': remove_greater, '<': remove_smaller, '=': remove_equal}
        if tokens[0].strip() not in sign_dict or not is_int(tokens[1].strip()):
            last_op.pop()
            raise ValueError("Wrong parameters")
        sign = tokens[0].strip()
        comp = int(tokens[1].strip())
        sign_dict[sign](score_list, comp, last_op)

def average_command_ui(calc, params):
    tokens = params.split(' ')
    if len(tokens) != 3 or tokens[1].strip().lower() != 'to':
        raise ValueError('Wrong parameters')
    poz1 = tokens[0].strip()
    poz2 = tokens[2].strip()
    score_list = get_list(calc)
    avg = avg_of_avg(score_list, poz1, poz2)
    print(avg)

def minimum_command_ui(calc, params):
    tokens = params.split(' ')
    if len(tokens) != 3 or tokens[1].strip().lower() != 'to':
        raise ValueError('Wrong parameters')
    poz1 = tokens[0].strip()
    poz2 = tokens[2].strip()
    score_list = get_list(calc)
    mn = minimum_avg(score_list, poz1, poz2)
    print(mn)

def top_command_ui(calc, params):
    score_list = get_list(calc)
    tokens = params.strip().split(' ', 1)
    if len(tokens) == 1:
        nr = tokens[0].strip()
        if not is_int(nr) or int(nr) not in range(len(score_list)):
            raise ValueError('Invalid number')
        nr = int(nr)
        lst = score_list.copy()
        sort_list_by_criteria(lst, True, average_score)
        print_list(lst[:nr])
    elif len(tokens) == 2:
        nr = tokens[0].strip()
        problem = tokens[1].lower().strip()
        if not is_int(nr) or int(nr) not in range(len(score_list)) or problem not in ['p1', 'p2', 'p3']:
            raise ValueError('Invalid number')
        nr = int(nr)
        problem_dict = {'p1': get_p1, 'p2': get_p2, 'p3': get_p3}
        lst = score_list.copy()
        sort_list_by_criteria(lst, True, problem_dict[problem])
        print_list(lst[:nr])
    else:
        raise ValueError("No parameters entered")

def undo_command_ui(calc, params):
    if params == '':
        undo(calc, None)
    else:
        undo(calc, params)
