import unittest


def prime(n):
    """
    Finds out if the given number is prime
    :param n: (int) the given number
    :return: True if the number is prime, False otherwise
    """
    for d in range(2, n//2 + 1):
        if n % d == 0:
            return False
    return True


def divide_prime(set, left, right):
    """
    The function finds and returns the largest prime number found on an even position in the list
    We assume that 0 is an even number
    :param set: (list) the given list of elements
    :param left: (int) the left bound of the list
    :param right: (int) the right bound of the list
    :return: the largest prime number found on an even position in the list or None if no such number is found
    """
    if left >= right:
        if right % 2 != 0:
            return None
        if not prime(set[right]):
            return None
        return set[right]
    m = (left+right)//2

    n1 = divide_prime(set, left, m)
    n2 = divide_prime(set, m+1, right)

    if None not in [n1, n2]:
        return max(n1, n2)
    if n1 == None:
        return n2
    if n2 == None:
        return n1

class MyTestCase(unittest.TestCase):
    def test_prime(self):
        r = prime(1)
        self.assertTrue(r)

        r = prime(2)
        self.assertTrue(r)

        r = prime(23)
        self.assertTrue(r)

        r = prime(22)
        self.assertFalse(r)

    def test_divide_prime(self):
        a = [5, 6, 7, 8, 9, 10, 4, 12, 13, 14, 15, 16, 17, 25, 19]
        r = divide_prime(a, 0, len(a)-1)
        self.assertEqual(r, 19)

        a = [10, 23, 4, 13, 9]
        r = divide_prime(a, 0, len(a)-1)
        self.assertEqual(r, None)

        a = [10, 101, 23, 4, 19]
        r = divide_prime(a, 0, len(a)-1)
        self.assertEqual(r, 23)

if __name__ == '__main__':
    unittest.main()
