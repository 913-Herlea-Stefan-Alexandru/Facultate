#
# Write the implementation for A3 in this file
#

#
# domain section is here (domain = numbers, transactions, expenses, etc.)
# getters / setters
# No print or input statements in this section
# Specification for all non-trivial functions (trivial usually means a one-liner)

def create_score(p1, p2, p3):
    '''
    Creates a dictionary with all of the scores of a student
    :param p1: int problem one score
    :param p2: int problem two score
    :param p3: int problem three score
    :return: dict {'P1': problem one score, 'P2': problem two score, 'P3': problem three score}
    Raise ValueError if at least one of the scores is not in the interval [0,10] or if the scores cannot be converted to
    integers
    '''
    if is_int(p1) and is_int(p2) and is_int(p3):
        p1 = int(p1)
        p2 = int(p2)
        p3 = int(p3)
    else:
        raise ValueError("Parameters must be integers")
    if (p1 < 0 or p1 > 10) or (p2 < 0 or p2 > 10) or (p3 < 0 or p3 > 10):
        raise ValueError("Score must be between 0 and 10")
    return {'P1': p1, 'P2': p2, 'P3': p3}

def get_p1(score):
    return score['P1']

def get_p2(score):
    return score['P2']

def get_p3(score):
    return score['P3']

def set_p1(score, new_score):
    if new_score < 0 or new_score > 10:
        raise ValueError("The score must be between 0 and 10")
    score['P1'] = new_score

def set_p2(score, new_score):
    if new_score < 0 or new_score > 10:
        raise ValueError("The score must be between 0 and 10")
    score['P2'] = new_score

def set_p3(score, new_score):
    if new_score < 0 or new_score > 10:
        raise ValueError("The score must be between 0 and 10")
    score['P3'] = new_score

def split_command(command):
    '''
    Splits the given command string into the command and parameters
    :param command: str: given command string
    :return: str, str: command word and parameters
    '''
    tokens = command.strip().split(' ', 1)
    cmd_word = tokens[0].lower().strip()
    cmd_params = tokens[1].strip() if len(tokens) == 2 else ''
    return cmd_word, cmd_params

def is_int(string):
    try:
        int(string)
        return True
    except ValueError:
        return False

def score_to_string(score):
    return 'P1: ' + str(get_p1(score)).rjust(2) + ', P2: ' + str(get_p2(score)).rjust(2) + ', P3: ' + str(get_p3(score)).rjust(2)

def average_score(score):
    return (get_p1(score)+get_p2(score)+get_p3(score)) / 3

def sort_list_by_criteria(list, rev, crit):
    list.sort(reverse = rev, key = crit)

# Functionalities section (functions that implement required features)
# No print or input statements in this section
# Specification for all non-trivial functions (trivial usually means a one-liner)
# Each function does one thing only
# Functions communicate using input parameters and their return values

def add_score(score_list, p1, p2, p3):
    '''
    Adds the given scores to the current list
    :param score_list: The current score list
    :param p1: str: score for problem 1
    :param p2: str: score for problem 2
    :param p3: str: score for problem 3
    :return: -
    '''
    score = create_score(p1, p2, p3)
    score_list.append(score)

def insert_score(score_list, p1, p2, p3, index):
    '''
    Inserts a given score at a given position in the list
    :param score_list: The current list of scores
    :param p1: str: score for problem 1
    :param p2: str: score for problem 2
    :param p3: str: score for problem 3
    :param index: str: the position where the insertion takes place
    :return: -
    Raises ValueError if the index cannot be converted to an integer
    '''
    score = create_score(p1, p2, p3)
    if is_int(index):
        index = int(index)
    else:
        raise ValueError("Index must be an int")
    score_list.insert(index, score)

def replace_score(score_list, student, problem, new_score):
    '''
    Replaces the score of a given student at a given problem
    :param student: str: the index of the student
    :param problem: str: the problem which needs changes
    :param new_score: str: the new score of that problem
    :return: -
    Raises ValueError if the student or the new score cannot be converted to an integer or if the problem name is
    not valid or f the student is not in the list
    '''
    problem_dict = {'P1': set_p1, 'P2': set_p2, 'P3': set_p3}
    if not is_int(student) or not is_int(new_score) or problem.upper() not in problem_dict:
        raise ValueError("Invalid parameters")
    student = int(student)
    new_score = int(new_score)
    if student > len(score_list)-1:
        raise ValueError("Student not found")
    problem_dict[problem.upper()](score_list[student], new_score)

def remove_score_param(score_list, student):
    '''
    Replaces the scores of the given student with 0
    :param score_list: the current list of scores
    :param student: str: the given student
    :return:-
    Raises ValueError if the index cannot be converted to an integer
    '''
    if not is_int(student):
        raise ValueError("Index should be an integer")
    student = int(student)
    if student > len(score_list)-1:
        raise ValueError("Student not found")
    set_p1(score_list[student], 0)
    set_p2(score_list[student], 0)
    set_p3(score_list[student], 0)

def remove_score_interval(score_list, poz1, poz2):
    '''
    Replaces the scores of the students in the given interval with 0
    :param score_list: the current list of scores
    :param poz1: str: the start of the interval
    :param poz2: str: the end of the interval
    :return: -
    '''
    if not is_int(poz1) or not is_int(poz2):
        raise ValueError("Pozitions should be integers")
    poz1 = int(poz1)
    poz2 = int(poz2)
    for student in range(poz1, poz2+1):
        remove_score_param(score_list, student)

def list_greater(score_list, param):
    new_list = [score for score in score_list if average_score(score) > param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

def list_smaller(score_list, param):
    new_list = [score for score in score_list if average_score(score) < param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

def list_equal(score_list, param):
    new_list = [score for score in score_list if int(average_score(score)) == param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

# UI section
# (all functions that have input or print statements, or that CALL functions with print / input are  here).
# Ideally, this section should not contain any calculations relevant to program functionalities

def print_list(score_list):
    for index in range(len(score_list)):
        print((str(index) + '. ').ljust(4) + score_to_string(score_list[index]))

def add_score_command_ui(score_list, params):
    scores = params.split(' ')
    if params == '' or len(scores) != 3:
        raise ValueError("Missing Parameters")
    p1 = scores[0].strip()
    p2 = scores[1].strip()
    p3 = scores[2].strip()
    add_score(score_list, p1, p2, p3)

def insert_score_command_ui(score_list, params):
    tokens = params.split(' ')
    if len(tokens) != 5 or tokens[3].strip() != 'at':
        raise ValueError("Wrong parameters")
    p1 = tokens[0]
    p2 = tokens[1]
    p3 = tokens[2]
    index = tokens[4]
    insert_score(score_list, p1, p2, p3, index)

def print_list_command_ui(score_list, params):
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

def replace_score_command_ui(score_list, params):
    tokens = params.split(' ')
    if len(tokens) != 4 or tokens[2].lower().strip() != 'with':
        raise ValueError("Wrong parameters")
    student = tokens[0].strip()
    problem = tokens[1].strip()
    new_score = tokens[3].strip()
    replace_score(score_list, student, problem, new_score)

def remove_score_command_ui(score_list, params):
    if len(params.split(' ')) == 1:
        remove_score_param(score_list, params)
    elif params == '':
        raise ValueError("Please enter parameters")
    else:
        tokens = params.split(' ')
        if len(tokens) != 3 or tokens[1].strip() != 'to':
            raise ValueError("Wrong parameters")
        poz1 = tokens[0].strip()
        poz2 = tokens[2].strip()
        remove_score_interval(score_list, poz1, poz2)

def start_command_ui():
    '''
    Handles user commands and all of the functionalities of the program
    :return: -
    '''
    is_running = True
    command_dict = {'add': add_score_command_ui, 'insert': insert_score_command_ui, 'list': print_list_command_ui, 'replace': replace_score_command_ui, 'remove': remove_score_command_ui}
    score_list = []
    test_init(score_list)
    while is_running:
        command = input("command>> ")
        command_word, command_params = split_command(command)
        if command_word in command_dict:
            try:
                command_dict[command_word](score_list, command_params)
            except ValueError as ve:
                print(str(ve))
        elif command_word == 'exit':
            is_running = False
        else:
            print("Wrong command")


# Test functions go here
#
# Test functions:
#   - no print / input
#   - great friends with assert

def test_init(test_list):
    test_list.append(create_score(8, 7, 9))
    test_list.append(create_score(4, 10, 9))
    test_list.append(create_score(9, 8, 7))
    test_list.append(create_score(2, 5, 4))
    test_list.append(create_score(1, 2, 1))
    test_list.append(create_score(10, 6, 10))
    test_list.append(create_score(5, 9, 8))
    test_list.append(create_score(8, 3, 6))
    test_list.append(create_score(3, 1, 10))
    test_list.append(create_score(6, 7, 5))

def test_create_score():
    p1 = 8
    p2 = 1
    p3 = 10
    student = create_score(p1, p2, p3)
    assert get_p1(student) == 8 and get_p2(student) == 1 and get_p3(student) == 10
    p1 = 5
    p2 = 11
    p3 = -5
    try:
        student = create_score(p1, p2, p3)
        assert False
    except ValueError:
        assert True

def test_split_command():
    cmd = ['add 3 6 5', '   InsErT   10 10 9 at 5     ', '  reMove    5  ', '  ReplaCe   4 P2 with 5']
    cmd_word, cmd_param = split_command(cmd[0])
    assert cmd_word == 'add' and cmd_param == '3 6 5'
    cmd_word, cmd_param = split_command(cmd[1])
    assert cmd_word == 'insert' and cmd_param == '10 10 9 at 5'
    cmd_word, cmd_param = split_command(cmd[2])
    assert cmd_word == 'remove' and cmd_param == '5'
    cmd_word, cmd_param = split_command(cmd[3])
    assert cmd_word == 'replace' and cmd_param == '4 P2 with 5'

def test_add_score_command_ui():
    list = []
    test_init(list)
    list_len = len(list)
    add_score_command_ui(list, '5 7 6')
    p1 = get_p1(list[len(list) - 1])
    p2 = get_p2(list[len(list) - 1])
    p3 = get_p3(list[len(list) - 1])
    assert p1 == 5 and p2 == 7 and p3 == 6 and list_len == len(list)-1
    try:
        add_score_command_ui(list, '6 11 -5')
        assert False
    except ValueError:
        assert True
    try:
        add_score_command_ui(list, '6 ff 5')
        assert False
    except ValueError:
        assert True

def test_insert_score_command_ui():
    list = []
    test_init(list)
    list_len = len(list)
    insert_score_command_ui(list, '10 10 9 at 5')
    p1 = get_p1(list[5])
    p2 = get_p2(list[5])
    p3 = get_p3(list[5])
    assert p1 == 10 and p2 == 10 and p3 == 9 and list_len == len(list)-1
    try:
        insert_score_command_ui(list, '7 6 5 at ff')
        assert False
    except ValueError:
        assert True
    try:
        insert_score_command_ui(list, '9 0 1 h 3')
        assert False
    except ValueError:
        assert True

def test_print_list():
    list = []
    test_init(list)
    print_list_command_ui(list, '< 4')
    print()
    print_list_command_ui(list, '')
    assert len(list_equal(list, 8)) == 3 and get_p2(list_equal(list, 8)[2]) == 6
    assert len(list_greater(list, 8)) == 1
    assert len(list_smaller(list, 4)) == 2
    try:
        print_list_command_ui(list, 'dsf rrr')
        print_list_command_ui(list, '= rrr')
        print_list_command_ui(list, 'sdrt')
        assert False
    except ValueError:
        assert True

def test_replace_score_command_ui():
    list = []
    test_init(list)
    replace_score_command_ui(list, '4 P1 with 10')
    assert get_p1(list[4]) == 10
    replace_score_command_ui(list, '9 P3 with 0')
    assert get_p3(list[9]) == 0
    try:
        replace_score_command_ui(list, '11 p1 with 4')
        replace_score_command_ui(list, '3 ewf with 3')
        replace_score_command_ui(list, '2 p2 with 11')
        assert False
    except ValueError:
        assert True

def test_remove_score_command_ui():
    list = []
    test_init(list)
    remove_score_command_ui(list, '4')
    assert get_p1(list[4]) == 0 and get_p2(list[4]) == 0 and get_p3(list[4]) == 0
    remove_score_command_ui(list, '5 to 9')
    for index in range(5, 10):
        assert get_p1(list[index]) == 0 and get_p2(list[index]) == 0 and get_p3(list[index]) == 0
    try:
        remove_score_command_ui(list, ' df ')
        remove_score_command_ui(list, '11 to 19')
        assert False
    except ValueError:
        assert True

#test_add_score_command_ui()
#test_split_command()
#test_create_score()
#test_insert_score_command_ui()
#test_print_list()
#test_replace_score_command_ui()
#test_remove_score_command_ui()


start_command_ui()
