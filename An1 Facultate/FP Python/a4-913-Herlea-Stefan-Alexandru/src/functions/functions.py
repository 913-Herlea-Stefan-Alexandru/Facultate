"""
Functions that implement program features. They should call each other, or other functions from the domain
"""

from src.domain.entity import *

def create_calc(score_list):
    '''
    Creates a new calculator as a dictionary with the given list of scores as it's first element and an empty list
    as it's last operation element
    :param score_list: the current list of scores
    :return: dictionary with the given list of scores as it's first element and an empty list
    as it's last operation element
    '''
    return {'score_list': score_list, 'last_op': []}

def get_list(calc):
    return calc['score_list']

def get_last_op(calc):
    return calc['last_op']

def set_list(calc, list):
    calc['score_list'] = list.copy()

def add_score(score_list, p1, p2, p3, last_op):
    '''
    Adds the given scores to the current list
    :param score_list: The current score list
    :param p1: str: score for problem 1
    :param p2: str: score for problem 2
    :param p3: str: score for problem 3
    :return: -
    Raises ValueError if the scores cannot be converted to integers or the scores are not in [0,10]
    '''
    if is_int(p1) and is_int(p2) and is_int(p3):
        p1 = int(p1)
        p2 = int(p2)
        p3 = int(p3)
    else:
        last_op.pop()
        raise ValueError("Parameters must be integers")
    if (p1 < 0 or p1 > 10) or (p2 < 0 or p2 > 10) or (p3 < 0 or p3 > 10):
        last_op.pop()
        raise ValueError("Score must be between 0 and 10")
    score = create_score(p1, p2, p3)
    score_list.append(score)

def insert_score(score_list, p1, p2, p3, index, last_op):
    '''
    Inserts a given score at a given position in the list
    :param score_list: The current list of scores
    :param p1: str: score for problem 1
    :param p2: str: score for problem 2
    :param p3: str: score for problem 3
    :param index: str: the position where the insertion takes place
    :return: -
    Raises ValueError if the index cannot be converted to an integer or the scores are not in [0,10]
    '''
    if is_int(p1) and is_int(p2) and is_int(p3):
        p1 = int(p1)
        p2 = int(p2)
        p3 = int(p3)
    else:
        last_op.pop()
        raise ValueError("Parameters must be integers")
    if (p1 < 0 or p1 > 10) or (p2 < 0 or p2 > 10) or (p3 < 0 or p3 > 10):
        last_op.pop()
        raise ValueError("Score must be between 0 and 10")
    score = create_score(p1, p2, p3)
    if is_int(index):
        index = int(index)
    else:
        last_op.pop()
        raise ValueError("Index must be an int")
    score_list.insert(index, score)

def replace_score(score_list, student, problem, new_score, last_op):
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
        last_op.pop()
        raise ValueError("Invalid parameters")
    student = int(student)
    new_score = int(new_score)
    if new_score < 0 or new_score > 10:
        last_op.pop()
        raise ValueError("The score must be between 0 and 10")
    if student > len(score_list)-1:
        last_op.pop()
        raise ValueError("Student not found")
    problem_dict[problem.upper()](score_list[student], new_score)

def remove_score_param(score_list, student, last_op):
    '''
    Replaces the scores of the given student with 0
    :param score_list: the current list of scores
    :param student: str: the given student
    :return:-
    Raises ValueError if the index cannot be converted to an integer or the student is not found
    '''
    if not is_int(student):
        last_op.pop()
        raise ValueError("Index should be an integer")
    student = int(student)
    if student > len(score_list)-1:
        last_op.pop()
        raise ValueError("Student not found")
    set_p1(score_list[student], 0)
    set_p2(score_list[student], 0)
    set_p3(score_list[student], 0)

def remove_score_interval(score_list, poz1, poz2, last_op):
    '''
    Replaces the scores of the students in the given interval with 0
    :param score_list: the current list of scores
    :param poz1: str: the start of the interval
    :param poz2: str: the end of the interval
    :return: -
    Raises ValueError if the parameters are not integers or the positions are out of range
    '''
    if not is_int(poz1) or not is_int(poz2):
        last_op.pop()
        raise ValueError("Positions should be integers")
    poz1 = int(poz1)
    poz2 = int(poz2)
    if poz1 < 0 or poz2 > len(score_list):
        last_op.pop()
        raise ValueError("Positions out of range")
    if poz2 < poz1:
        poz1, poz2 = poz2, poz1
    for student in range(poz1, poz2+1):
        remove_score_param(score_list, student, last_op)

def list_greater(score_list, param):
    '''
    Returns the sublist with students with average scores grater than a given number
    :param score_list: the current list of scores
    :param param: int: the average score to compare each element
    :return: the sublist with students with average scores grater than a given number
    Raises ValueError if there are no scores with the given average score
    '''
    new_list = [score for score in score_list if average_score(score) > param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

def list_smaller(score_list, param):
    '''
    Returns the sublist with students with average scores smaller than a given number
    :param score_list: the current list of scores
    :param param: int: the average score to compare each element
    :return: the sublist with students with average scores smaller than a given number
    Raises ValueError if there are no scores with the given average score
    '''
    new_list = [score for score in score_list if average_score(score) < param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

def list_equal(score_list, param):
    '''
    Returns the sublist with students with average scores equal with a given number
    :param score_list: the current list of scores
    :param param: int: the average score to compare each element
    :return: the sublist with students with average scores equal with a given number
    Raises ValueError if there are no scores with the given average score
    '''
    new_list = [score for score in score_list if int(average_score(score)) == param]
    if new_list == []:
        raise ValueError("No score found")
    return new_list

def score_to_string(score):
    return 'P1: ' + str(get_p1(score)).rjust(2) + ', P2: ' + str(get_p2(score)).rjust(2) + ', P3: ' + str(get_p3(score)).rjust(2)

def average_score(score):
    return (get_p1(score)+get_p2(score)+get_p3(score)) / 3

def sort_list_by_criteria(list, rev, crit):
    list.sort(reverse = rev, key = crit)

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

def Average(list):
    return sum(list)/float(len(list))

def avg_of_avg(score_list, poz1, poz2):
    '''
    Returns the average of the average scores in the interval from the list
    :param score_list: the current list of scores
    :param poz1: position to begin the top
    :param poz2: position to end the top
    :return: int: Returns the average of the average scores in the interval from the list
    Raises ValueError if the parameters are not integers
    '''
    if not is_int(poz1) or not is_int(poz2):
        raise ValueError("Positions should be integers")
    poz1 = int(poz1)
    poz2 = int(poz2)
    if poz2 < poz1:
        poz1, poz2 = poz2, poz1
    return Average([average_score(score) for score in score_list[poz1:poz2+1]])

def minimum_avg(score_list, poz1, poz2):
    '''
    Returns the minimum average score in the interval from the list
    :param score_list: the current list of numbers
    :param poz1: position to begin the top
    :param poz2: position to end the top
    :return: Returns the minimum average score in the interval from the list
    Raises ValueError if parameters are not integers
    '''
    if not is_int(poz1) or not is_int(poz2):
        raise ValueError("Positions should be integers")
    poz1 = int(poz1)
    poz2 = int(poz2)
    if poz2 < poz1:
        poz1, poz2 = poz2, poz1
    return min([average_score(score) for score in score_list[poz1:poz2+1]])

def remove_greater(score_list, comp, last_op):
    '''
    Removes each student with an average score greater than a given number
    :param score_list: the current list of scores
    :param comp: int: the average score to compare each element
    :param last_op: the list of last operations performed
    :return: -
    Raises ValueError if the comparison is not in [0.10]
    '''
    if comp not in range(11):
        last_op.pop()
        raise ValueError('Average should be in [0,10]')
    is_inside = False
    for index in range(len(score_list)):
        if average_score(score_list[index]) > comp:
            is_inside = True
            remove_score_param(score_list, index, last_op)
    if not is_inside:
        last_op.pop()
        raise ValueError('No scores found')

def remove_smaller(score_list, comp, last_op):
    '''
    Removes each student with an average score smaller than a given number
    :param score_list: the current list of scores
    :param comp: int: the average score to compare each element
    :param last_op: the list of last operations performed
    :return: -
    Raises ValueError if the comparison is not in [0.10]
    '''
    if comp not in range(11):
        last_op.pop()
        raise ValueError('Average should be in [0,10]')
    is_inside = False
    for index in range(len(score_list)):
        if average_score(score_list[index]) < comp:
            is_inside = True
            remove_score_param(score_list, index, last_op)
    if not is_inside:
        last_op.pop()
        raise ValueError('No scores found')

def remove_equal(score_list, comp, last_op):
    '''
    Removes each student with an average score equal with a given number
    :param score_list: the current list of scores
    :param comp: int: the average score to compare each element
    :param last_op: the list of last operations performed
    :return: -
    Raises ValueError if the comparison is not in [0.10]
    '''
    if comp not in range(11):
        last_op.pop()
        raise ValueError('Average should be in [0,10]')
    is_inside = False
    for index in range(len(score_list)):
        if int(average_score(score_list[index])) == comp:
            is_inside = True
            remove_score_param(score_list, index, last_op)
    if not is_inside:
        last_op.pop()
        raise ValueError('No scores found')


def is_int(string):
    '''
    Checks if a string can be converted to an integer
    :param string: the string to check
    :return: True if it can be converted, False if it cannot
    '''
    try:
        int(string)
        return True
    except ValueError:
        return False

def add_to_last_op(score_list, last_op):
    last_op.append([])
    for i in range(len(score_list)):
        last_op[-1].append(score_list[i].copy())

def undo(calc, count):
    '''
    Reverts to the last known instance of the list. If given a count it reverts the number of times it says
    :param calc: the current calculator (dict)
    :param count: str: if is given or None if not
    :return: -
    Raises ValueError if there is no operation to undo or if given wrong parameters
    '''
    if count == None:
        last_op = get_last_op(calc)
        if last_op == []:
            raise ValueError("No operation to undo")
        set_list(calc, last_op[-1])
        last_op.pop()
    else:
        if not is_int(count):
            raise ValueError("Wrong parameters")
        last_op = get_last_op(calc)
        count = int(count)
        for index in range(count):
            if last_op == []:
                raise ValueError("No operation to undo")
            set_list(calc, last_op[-1])
            last_op.pop()

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

def test_add_score():
    test_list = []
    test_init(test_list)
    add_score(test_list, 10, 10, 10, [1])
    assert len(test_list) == 11 and test_list[10] == create_score(10, 10, 10)
    try:
        add_score(test_list, -2, 7, 11, [1])
        add_score(test_list, 'fg', 55, 'rr', [1])
        assert False
    except ValueError:
        assert True

def test_insert_score():
    test_list = []
    test_init(test_list)
    insert_score(test_list, 5, 5, 5, 4, [1])
    assert len(test_list) == 11 and test_list[4] == create_score(5, 5, 5)
    try:
        insert_score(test_list, 11, 5, 5, 2, [1])
        insert_score(test_list, 'gr', 5, 5, 9, [1])
        assert False
    except ValueError:
        assert True

def test_replace_score():
    test_list = []
    test_init(test_list)
    replace_score(test_list, 4, 'P3', 10, [1])
    assert test_list[4] == create_score(1, 2, 10)
    try:
        replace_score(test_list, 99, 'rg', 19, [1])
        assert False
    except ValueError:
        assert True

def test_remove_score_interval():
    test_list = []
    test_init(test_list)
    remove_score_interval(test_list, 0, 5, [1])
    c = test_list.count(create_score(0, 0, 0))
    assert c == 6
    try:
        remove_score_interval(test_list, -3, 5, [1])
        remove_score_interval(test_list, 0, 99, [1])
        assert False
    except ValueError:
        assert True

def test_list_return():
    test_list = []
    test_init(test_list)
    great = list_greater(test_list, 5)
    assert len(great) == 7
    small = list_smaller(test_list, 5)
    assert len(small) == 3
    equal = list_equal(test_list, 5)
    assert len(equal) == 1

def test_avg_of_avg():
    test_list = []
    test_init(test_list)
    assert avg_of_avg(test_list, 3, 7) == 5.333333333333334

def test_minimum_avg():
    test_list = []
    test_init(test_list)
    assert minimum_avg(test_list, 2, 5) == 1.3333333333333333

def test_remove_op():
    test_list = []
    test_init(test_list)
    remove_smaller(test_list, 3, [1])
    assert test_list[4] == create_score(0, 0, 0)
    remove_equal(test_list, 6, [1])
    assert test_list[9] == create_score(0, 0, 0)
    remove_greater(test_list, 8, [1])
    assert test_list[5] == create_score(0, 0, 0)

# test_add_score()
# test_insert_score()
# test_replace_score()
# test_remove_score_interval()
# test_list_return()
# test_avg_of_avg()
# test_minimum_avg()
# test_remove_op()