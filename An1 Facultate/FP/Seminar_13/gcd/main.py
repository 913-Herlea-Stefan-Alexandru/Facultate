def gcd(number1, number2):
    '''
    Computes the greatest common divisor between two elements
    :param number1: (int)
    :param number2: (int)
    :return: the greatest common divisor between two elements
    '''
    if number2 == 0:
        return number1
    return gcd(number2, number1 % number2)

def div_conq_gcd(elements):
    '''
    Computes the greatest common divisor between every elements of the list
    :param elements: the list of elements
    :return: the greatest common divisor between every elements of the list
    '''
    if len(elements) == 1:
        return elements[0]

    nr1 = div_conq_gcd(elements[:len(elements)//2])
    nr2 = div_conq_gcd(elements[len(elements)//2:])

    return gcd(nr1, nr2)

def test():
    elements = [8, 32, 64, 4, 16]

    assert div_conq_gcd(elements) == 4

test()
