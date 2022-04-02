'''
    6. Generate all sequences of n parentheses that close correctly.
    Example: for n=4 there are two solutions: (()) and ()()
'''

def print_solution(solution):
    '''
    Used to print solutions into a readable string of characters
    :param solution: (list of char) the current solution
    :return: -
    '''
    solution_string = ''
    for element in solution:
        solution_string += element
    print(solution_string)

def next_element(current_list):
    '''
    Checks if the program can advance to the next element in the list and does so if possible
    :param current_list: the current list of indexes of elements (list of int)
    :return: True if it can go to the next element in the list, False if it can't
    '''
    if current_list[-1] == 1:
        return False
    current_list[-1] += 1
    return True

def is_consistent(current_list, n):
    '''
    Checks if the current list of indexes of elements forms a consistent list for future solutions
    :param current_list: the current list of indexes of elements (list of int)
    :param n: the number of elements that should be in the final list (int)
    :return: True if the list is consistent, False if it is not (i.e. it has more elements than the maximum amount,
    the number of closed brackets is larger than the number of open brackets at any given point)
    '''
    number_open_brackets = current_list.count(0)
    number_closed_brackets = current_list.count(1)
    if len(current_list) > n:
        return False
    if number_closed_brackets > number_open_brackets:
        return False
    return True

def is_solution(current_list, n):
    '''
    Checks if the current list is a solution
    :param current_list: the current list of indexes of elements (list of int)
    :param n: the number of elements that should be in the final list (int)
    :return: True if it is a solution, False if it is not (i.e. the length of the list is not n, the last element is not
    a closed bracket, the number of closed brackets is not equal to the number of open brackets)
    '''
    number_open_brackets = current_list.count(0)
    number_closed_brackets = current_list.count(1)
    if len(current_list) != n:
        return False
    if current_list[-1] != 1:
        return False
    if number_closed_brackets != number_open_brackets:
        return False
    return True

def add_solution(current_list, elements_list, solution_list):
    '''
    Adds the newly found solution to the solution list
    :param current_list: the current list of indexes of elements (list of int)
    :param elements_list: the list of elements that form a solution (list of char)
    :param solution_list: the list of all found solutions (list of list)
    :return: -
    '''
    solution = []
    for i in current_list:
        solution.append(elements_list[i])
    solution_list.append(solution)

def expand(current_list):
    '''
    Expands the current list by adding one element
    :param current_list: the current list of indexes of elements (list of int)
    :return: -
    '''
    current_list.append(-1)

def backtrack(current_list):
    '''
    Checks if the program can backtrack to the previous element in the list
    :param current_list: the current list of indexes of elements (list of int)
    :return: True if it can, False if it can't
    '''
    current_list.pop()
    if len(current_list) == 0:
        return False
    return True

def iterative_brackets(n):
    '''
    An iterative version of the brackets building algorithm using backtracking
    :param n: the number of brackets in the solution (int)
    :return: the whole solution list or None if there are no solutions
    '''
    if n % 2 == 1:
        return None
    solution_list = []
    elements_list = ['(', ')']
    current_list = [-1]
    searching = True
    while searching:
        while next_element(current_list):
            if is_consistent(current_list, n):
                if is_solution(current_list, n):
                    add_solution(current_list, elements_list, solution_list)
                else:
                    expand(current_list)
        if not backtrack(current_list):
            searching = False
    return solution_list

def recursive_brackets(current_list, elements_list, n, solution_list):
    '''
    A recursive version of the brackets building algorithm using backtracking
    :param current_list: the current list of indexes of elements (list of int)
    :param elements_list: the list of elements that form a solution (list of char)
    :param n: the number of brackets in the solution (int)
    :param solution_list: the list of all found solutions (list of list)
    :return: the whole solution list or None if there are no solutions
    '''
    if n % 2 == 1:
        return None
    expand(current_list)
    while next_element(current_list):
        if is_consistent(current_list, n):
            if is_solution(current_list, n):
                add_solution(current_list, elements_list, solution_list)
            else:
                recursive_brackets(current_list, elements_list, n, solution_list)
    if not backtrack(current_list):
        return solution_list

def test():
    elements_list = ['(', ')']
    solution = []

    # solution = recursive_brackets([], elements_list, 6, solution)
    solution = iterative_brackets(4)

    if solution == None:
        print('No solution for given n')
    else:
        for sol in solution:
            print_solution(sol)

test()
