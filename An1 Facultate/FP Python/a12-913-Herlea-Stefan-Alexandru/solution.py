'''
5. The sequence a = a1, ..., an with distinct integer numbers is given. Determine all subsets of elements having the sum
divisible by a given n.
'''

def print_solution(solution):
    '''
    Used to print solutions into a readable string of characters
    :param solution: (list of int) the current solution
    :return: -
    '''
    solution_string = ''
    for element in solution:
        solution_string += str(element) + ' '
    print(solution_string)

def next_element(current_list, max_length):
    '''
    Checks if the program can advance to the next element in the list and does so if possible
    :param current_list: the current list of indexes of elements (list of int)
    :param max_length: the maximum length of the list (int)
    :return: True if it can go to the next element in the list, False if it can't
    '''
    if current_list[-1] >= max_length-1:
        return False
    if len(current_list) != 1 and current_list[-1] != current_list[-2]:
        return False
    current_list[-1] += 1
    return True

def is_consistent(current_list, max_length):
    '''
    Checks if the current list of indexes of elements forms a consistent list for future solutions
    :param current_list: the current list of indexes of elements (list of int)
    :param max_length: the maximum number of elements that should be in the final list (int)
    :return: True if the list is consistent, False if it is not
    '''
    if len(current_list) > max_length:
        return False
    return True

def is_solution(current_list, elements_list, n):
    '''
    Checks if the current list is a solution
    :param current_list: the current list of indexes of elements (list of int)
    :param elements_list: the list of actual elements that will be in the solution (list of int)
    :param n: the number at which the sum of the elements should divide (int)
    :return: True if it is a solution, False if it is not
    '''
    S = sum([elements_list[i] for i in current_list])
    if S % n != 0:
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
    current_list.append(current_list[-1])

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

def iterative_back(elements_list, n, solution_list):
    '''
    An iterative version of the algorithm
    :param n: the number of brackets in the solution (int)
    :return: the whole solution list or None if there are no solutions
    '''
    current_list = [-1]
    searching = True
    while searching:
        while next_element(current_list, len(elements_list)):
            if is_consistent(current_list, len(elements_list)):
                if is_solution(current_list, elements_list, n):
                    add_solution(current_list, elements_list, solution_list)
                expand(current_list)
        if not backtrack(current_list):
            searching = False
    return solution_list

def recursive_back(current_list, elements_list, n, solution_list):
    '''
    A recursive version of the algorithm
    :param current_list: the current list of indexes of elements (list of int)
    :param elements_list: the list of elements that form a solution (list of char)
    :param n: the number the subset's sum should divide to (int)
    :param solution_list: the list of all found solutions (list of list)
    :return: the whole solution list
    '''
    if len(current_list) == 0:
        current_list.append(-1)
    else:
        expand(current_list)
    while next_element(current_list, len(elements_list)):
        if is_consistent(current_list, len(elements_list)):
            if is_solution(current_list, elements_list, n):
                add_solution(current_list, elements_list, solution_list)
            recursive_back(current_list, elements_list, n, solution_list)
    if not backtrack(current_list):
        return solution_list

def test():
    elements_list = [2, 4, 1, 5, 6, 3, 7]
    solution = []

    solution = recursive_back([], elements_list, 6, solution)
    # solution = iterative_back(elements_list, 4, solution)

    if solution == None:
        print('No solution for given n')
    else:
        for sol in solution:
            print_solution(sol)

test()
