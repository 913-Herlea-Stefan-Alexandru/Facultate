def gnome_sort(array, function, upperBound):
    '''
    It moves the element at the position given by the upperBound in the array to the left until the condition of the
    sort is not met anymore or it gets into the first position of the array, then the function exits.
    :param array: the array to sort (list)
    :param function: the function giving the sorting conditions
    :param upperBound: the initial position of the element that has to be moved (integer)
    :return: -
    '''
    while upperBound > 0 and function(array[upperBound-1]) < function(array[upperBound]):
        array[upperBound-1], array[upperBound] = array[upperBound], array[upperBound-1]
        upperBound -= 1

def sort(array, function):
    '''
    The function takes each element except for the first one of the array and moves it to the left if the given
    conditions are met.
    :param array: the array to sort (list)
    :param function: the function giving the sorting conditions
    :return: -
    '''
    for i in range(len(array)):
        gnome_sort(array, function, i)