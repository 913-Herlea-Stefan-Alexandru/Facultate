#
# Write the implementation for A2 in this file
#

from math import sqrt

# UI section
# (write all functions that have input or print statements here). 
# Ideally, this section should not contain any calculations relevant to program functionalities

def read_list(n, complex_list):
    '''
    Creates a list of complex numbers
    :param n: the length of the list (integer)
    :return: the complex numbers list
    '''
    i = 0
    while i < n:
        comp = read_complex()
        if comp != None:
            complex_list.append(comp)
            i += 1

def read_complex():
    '''
    Reading the real and imaginary part of a complex number and handles the errors if you don't
    read a number
    :param i: the index of the number read (integer)
    :return: the complex number as a dictionary or nothing if there is an error
    '''
    try:
        real = int(input("\tReal part of number: "))
        imag = int(input("\tImaginary part of number: "))
        return construct_complex(real, imag)
    except ValueError:
        print("Invalid entry")
        return None

def write(complex):
    '''
    Writes the given complex number
    :param complex: the complex number to write (dictionary)
    :return: ---
    '''
    print(to_str(complex))

def add_complex_ui(complex_list):
    '''
    Adds a complex number to the list
    :param complex_list: The complex number list
    :return: ---
    '''
    complex = None
    while complex is None:
        complex = read_complex()
    complex_list.append(complex)

def remove_complex_ui(complex_list):
    '''
    Handles the user input for the removing functionality
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    try:
        index = int(input("\nEnter the index of the number you want to delete (counting starts with 1): "))
    except ValueError:
        print("Invalid entry")
        return
    remove_complex(complex_list, index)
    print_list_of_numbers(complex_list)

def print_list_of_numbers(list):
    '''
    Prints a list of complex numbers on the same line, separated by a ','
    :param list: the list of complex numbers
    :return: ---
    '''
    print(', '.join(to_str(x) for x in list))

def print_distinct_ui(complex_list):
    '''
    Prints the longest sequence of distinct numbers from the list
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    print_list_of_numbers(distinct(complex_list))

def print_equal_mod_ui(complex_list):
    '''
    Prints the longest sequence of numbers with the same modulus from the given list
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    print_list_of_numbers(equal_mod(complex_list))

def add_list_ui(complex_list):
    '''
    Adds an inserted number of elements to the list
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    comp_list2 = []
    n = input("How many numbers would you like to add? ")
    try:
        n = int(n)
    except ValueError:
        print("Invalid entry")
        return
    read_list(n, comp_list2)
    complex_list.extend(comp_list2)

def reset_ui(complex_list):
    '''
    Clears the list of elements and asks the user for input for a new list
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    n = input("How many numbers would you like to add? ")
    try:
        n = int(n)
    except ValueError:
        print("Invalid entry")
        return
    complex_list.clear()
    read_list(n, complex_list)

def UI_screen():
    '''
    Prints the user interface menu
    :return: ---
    '''
    print('\nChoose option: ')
    print('\t1. Add a complex number to the list')
    print('\t2. Add more complex numbers to the list')
    print('\t3. Print the list of complex numbers')
    print('\t4. Remove a number from the list')
    print('\t5. Reset the list')
    print('\t6. The longest sequence of numbers having the same modulus')
    print('\t7. The longest sequence of distinct numbers')
    print('\tx. Exit Program\n')


# Function section
# (write all non-UI functions in this section)
# There should be no print or input statements below this comment
# Each function should do one thing only
# Functions communicate using input parameters and their return values

# print('Hello A2'!) -> prints aren't allowed here!

def construct_complex(real=0, imag=0):
    '''
    Returns the complex number as a dictionary, given the real and imaginary part
    :param real: the real part of the complex number (integer)
    :param imag: the imaginary part of the complex number (integer)
    :return: the dictionary of the complex number
    '''
    return {'real': real, 'imaginary': imag}

def get_real(complex):
    '''
    Gives you the real part of a complex number
    :param complex: the complex number (dictionary)
    :return: the real part of the complex number (integer)
    '''
    return complex['real']

def get_imaginary(complex):
    '''
    Gives you the imaginary part of the complex number
    :param complex: the complex number (dictionary)
    :return: the imaginary part of the complex number (integer)
    '''
    return complex['imaginary']

def remove_complex(complex_list, index):
    '''
    Removes a complex number from the list, given it's index
    :param complex_list: The list of complex numbers
    :param index: The index of the number that has to be deleted
    :return: ---
    '''
    if index < len(complex_list) and index > 0:
        complex_list.pop(index - 1)
    else:
        print("Invalid entry")

def to_str(complex):
    '''
    Converts the complex number into it's normal form "a + bi" as a string
    :param complex: the complex number (dictionary)
    :return: the string form of the complex number
    '''
    com_str = ''
    if get_imaginary(complex) > 0:
        com_str = str(get_real(complex)) + '+' + str(get_imaginary(complex)) + 'i'
    elif get_imaginary(complex) == 0:
        com_str = str(get_real(complex))
    else:
        com_str = str(get_real(complex)) + str(get_imaginary(complex)) + 'i'
    return com_str

def distinct(list):
    '''
    Determines the largest sequence of distinct complex numbers by keeping track of the current sequence's
    margins. When we get to a number that is already part of the sequence, we see if the current sequence
    is larger than the previous one and if it is we save the current margins. We turn the index back to the first
    occurrence of the number which stopped the sequence, and we start a new one from the next number.
    :param list: the list of complex numbers
    :return: the largest sequence of distinct complex numbers as a list
    '''
    p1 = 0
    p2 = 0
    e1 = None
    e2 = None
    longest = 0
    i = 0
    while i < len(list):
        if longest == 0:
            p2 = 1
            longest = 1
            e1 = p1
            e2 = p2
        elif list[i] in list[p1:p2]:
            if p2-p1 > longest:
                longest = p2-p1
                e1 = p1
                e2 = p2
            i = list[p1:p2].index(list[i])+p1+1
            p1 = i
            p2 = p1+1
        else:
            p2 += 1
        i += 1
    if p2-p1 > longest:
        e1 = p1
        e2 = p2
    return list[e1:e2]

def mod(complex):
    '''
    Calculates the modulus of a complex number
    :param complex: the complex number (dictionary)
    :return: the modulus of the complex number
    '''
    return sqrt((pow(get_real(complex), 2)+pow(get_imaginary(complex), 2)))

def equal_mod(list):
    '''
    Determines the largest sequence of numbers of the same modulus by keeping track of the current sequence's
    margins. When the modulus changes, we check if the current sequence is larger than the previous one and
    if it is we save the current margins.
    :param list: the list of complex numbers
    :return: the largest sequence of numbers of the same modulus as a list
    '''
    p1 = 0
    p2 = 0
    e1 = None
    e2 = None
    longest = 0
    for i in range(len(list)):
        if longest == 0:
            p2 = 1
            longest = 1
            e1 = p1
            e2 = p2
        elif mod(list[i]) != mod(list[i-1]):
            if p2 - p1 > longest:
                longest = p2 - p1
                e1 = p1
                e2 = p2
            p1 = p2
            p2 += 1
        else:
            p2 += 1
    if p2-p1 > longest:
        e1 = p1
        e2 = p2
    return list[e1:e2]

def start_menu_ui():
    '''
    The main function in which the whole program is pieced together. Here is the main loop of the program which
    doesn't end until 'running' turns false (in user_input_handling). This is also where the reset option is
    handled 
    :return: ---
    '''
    complex_list = []
    list_init(complex_list)
    print_list_of_numbers(complex_list)
    command_dic = {'1': add_complex_ui,'2': add_list_ui,'3': print_list_of_numbers,'4': remove_complex_ui,'5': reset_ui,'6': print_equal_mod_ui,'7': print_distinct_ui}
    running = True
    while running:
        UI_screen()
        command = input("Enter command: ")
        if command == 'x':
            running = False
        elif command not in command_dic:
            print("Invalid command")
        else:
            command_dic[command](complex_list)

def list_init(complex_list):
    '''
    Creates 10 initial values for the list of complex numbers
    :param complex_list: The list of complex numbers
    :return: ---
    '''
    complex_list.append(construct_complex(1, 2))
    complex_list.append(construct_complex(3, 4))
    complex_list.append(construct_complex(5, 6))
    complex_list.append(construct_complex(1, 2))
    complex_list.append(construct_complex(3, 4))
    complex_list.append(construct_complex(6, 5))
    complex_list.append(construct_complex(7, 8))
    complex_list.append(construct_complex(9, 8))
    complex_list.append(construct_complex(1, 2))
    complex_list.append(construct_complex(3, 4))

start_menu_ui()