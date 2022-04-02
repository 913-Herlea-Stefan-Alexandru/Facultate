#
# Implement the program to solve the problem statement from the third set here
#

#13. Determine the `n-th`  element of the sequence `1,2,3,2,5,2,3,7,2,3,2,5,...` obtained from the sequence of natural numbers
#by replacing composed numbers with their prime divisors, without memorizing the elements of the sequence.

def reading():
    '''
    Reads number n
    :return: user input
    '''
    n = input("Value of n is: ")
    return n

def div(x, n):
    '''
    We check the natural number x's for divisors. If we find a prime divisor we keep it in d1
    and keep searching until either the counter goes to zero or there are no more divisors.
    If it has no divisors then it returns the number and decreases the counter by one
    :param x: the next number from the sequence of natural numbers
    :param n: counts down to find the n-th number of the sequence
    :return: the n-th number from the sequence and what remains of the counter
    '''
    d1 = None
    for d in range(2, (x//2)+1):
        if x%d == 0:
            d1 = d                  #d1 holds the value of the last prime divisor
            n -= 1
            if n <= 0:
                return d, n       #we check if the current divisor is the n-th element
            while x%d == 0:
                x /= d
    if d1 == None:
        return x, n-1              #if the number doesn't have prime divisors, we return the number
    else:
        return d1, n

def write(n):
    '''
    Writes the result
    :param n: The n-th number of the sequence
    :return: ---
    '''
    print("The n-th number of the sequence is: ", n)

def start():
    '''
    The main function
    :return:
    '''
    n = int(reading())
    i = 0
    nth = None
    while n > 0:
        i += 1
        nth, n = div(i, n)
    write(nth)

start()