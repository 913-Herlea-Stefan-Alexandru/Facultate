#
# Implement the program to solve the problem statement from the second set here
#

#8. Find the smallest number `m` from the Fibonacci sequence, defined by `f[0]=f[1]=1`, `f[n]=f[n-1] + f[n-2]`, for `n > 2`,
# larger than the given natural number `n`. (e.g. `for n = 6, m = 8`).

def reading():
    '''
    Reads number n
    :return: user input
    '''
    n = input("Value of n is: ")
    return n

def fib(x, y, z):
    '''
    Calculates the next element of the fibonacci sequence
    :param x: first number
    :param y: second number
    :param z: third number
    :return: returns the new first, second and third number
    '''
    return y, z, y+z

def write(m):
    '''
    Writes the result
    :param m: The smallest number in the Fibonacci sequence larger than n
    :return: ---
    '''
    print("The smallest number in the Fibonacci sequence larger than n is: ", m)

def start():
    '''
    The main function
    :return:
    '''
    n = int(reading())
    a = 1
    b = 2
    m = a+b
    while m <= n:       #Calculating the next element of the Fibonacci sequence until it is larger than n
        a, b, m = fib(a, b, m)
    write(m)

start()