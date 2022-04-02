
def initialise_matrix(n):
    '''
    Generates a matrix with it's first line as being the given list of elements
    :param n: the dimension of the matrix (int)
    :return: the matrix
    '''
    return [[i for i in range(n)]]

def next(n, current_line):
    '''
    Checks if it can go to the next element of the list, and does that id possible
    :param n: the length of the list / last element
    :param current_line: the list
    :return: True if it can go tu the next element, False if not
    '''
    if current_line[-1] >= n-1:
        return False
    current_line[-1] += 1
    return True

def consistent(matrix, current_line):
    '''
    Checks if the elements placed in the matrix are not repeating on either rows or collums
    :param matrix: the matrix
    :param current_line: te current line
    :return: True if no element repeats on row/collum, False if an element repeats
    '''
    if len(set(current_line)) != len(current_line):
        return False
    for i in range(len(current_line)):
        if current_line[i] in [matrix[j][i] for j in range(len(matrix)-1)]:
            return False
    return True

def solution_matrix(matrix, n):
    '''
    Checks if the matrix has all of it's lines
    :param matrix: the matrix
    :param n: the dimension of the matrix
    :return: True if it has n lines, False otherwise
    '''
    if len(matrix) != n:
        return False
    return True

def solution_line(current_line, n):
    '''
    Checks if the current line has all positions filled
    :param current_line: the current line
    :param n: the length o the line
    :return: True if the line is filled, false otherwise
    '''
    if len(current_line) != n:
        return False
    return True

def backtrack(current_line):
    '''
    Decides if we continue with the same line or we go to the previous one
    :param current_line: the current line
    :return: False if the line is empty, True otherwise
    '''
    current_line.pop()
    if len(current_line) == 1:
        return False
    return True

def print_solution(matrix):
    '''
    Prints the solution
    :param matrix: the matrix
    :return: -
    '''
    for line in matrix:
        print(line)
    print('\n')

def add_solution(matrix, solutions):
    sol = []
    for line in matrix:
        sol.append(line.copy())
    solutions.append(sol)

def one_line_back(matrix, line, n, solutions):
    '''
    Determines the reduced latin squares of size n
    :param matrix: the matrix used to represent the squares
    :param line: the current line position (int)
    :param n: the size of the square
    :return: -
    '''
    global k
    matrix.append([line, -1])
    while True:
        while next(n, matrix[-1]):
            if consistent(matrix, matrix[-1]):
                if solution_line(matrix[-1], n):
                    if solution_matrix(matrix, n):
                        add_solution(matrix, solutions)
                    else:
                        one_line_back(matrix, line+1, n, solutions)
                else:
                    matrix[-1].append(-1)
        if not backtrack(matrix[-1]):
            break
    matrix.pop()

def latin_sq_back(n):
    '''
    Generates all the latin squares of size n
    :param n: size of the square
    :return: all the latin squares of size n
    '''
    if n == 1:
        return [0]
    else:
        solutions = []
        matrix = initialise_matrix(n)
        one_line_back(matrix, 1, n, solutions)
        return solutions

def test():
    n = 4
    solutions = latin_sq_back(n)

    assert len(solutions) == 4

    for solution in solutions:
        print_solution(solution)

test()


