#
# Implement the program to solve the problem statement from the first set here
#

#1. Generate the first prime number larger than a given natural number `n`.

def reading():
    '''
    Reads number n
    :return: user input
    '''
    n = input("Value of n is: ")
    return n

def prime(x):
    '''
    Determines if number is prime
    :param x: the number
    :return: returns 0 if it is not prime and 1 if it is prime
    '''
    for d in range(2, x // 2):
        if x % d == 0:
            return 0
    return 1

def write(n):
    '''
    Writes the result
    :param n: The first prime number larger than n
    :return: ---
    '''
    print("The first prime number larger than n is: ", n)

def start():
    '''
    The main function
    :return:
    '''
    n = int(reading())
    ok = 0
    while ok == 0:
        n += 1
        ok = prime(n)
    write(n)

start()