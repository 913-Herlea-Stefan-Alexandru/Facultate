def max_sum(elements, left, middle, final):
    '''
    Computes the maximum sum between the the elements to the left of the middle, the elements to the right of the middle
    and the whole list of elements
    :param elements: the list of elements(list)
    :param left: the current left bound of the list (int)
    :param middle: the current middle point of the list (int)
    :param final: the current end of the list (int)
    :return: the maximum sum between the the elements to the left of the middle, the elements to the right of the middle
    and the whole list of elements
    '''
    S = 0
    left_sum = elements[middle]

    for i in range(middle, left - 1, -1):
        S += elements[i]

        if S > left_sum:
            left_sum = S

    S = 0
    right_sum = elements[middle+1]

    for i in range(middle + 1, final + 1):
        S += elements[i]

        if S > right_sum:
            right_sum = S

    return max(left_sum + right_sum, left_sum, right_sum)



def div_conq_max_subarray_sum(elements, left, final):
    '''
    Computes the maximum sum of elements between each subarray of the list
    :param elements: the list of elements (list)
    :param left: the current left bound of the list (int)
    :param final: the current right bound of the list (int)
    :return: the maximum sum of elements between each subarray of the list
    '''
    if left == final:
        return elements[left]

    middle = (left + final) // 2

    max1 = div_conq_max_subarray_sum(elements, left, middle)
    max2 = div_conq_max_subarray_sum(elements, middle + 1, final)
    max3 = max_sum(elements, left, middle, final)

    return max(max1, max2, max3)

def test():
    elements = [24, -5, -32, 68, 29, -1, 0, 39]

    final = len(elements)

    sum = div_conq_max_subarray_sum(elements, 0, final-1)

    assert sum == 135

test()
