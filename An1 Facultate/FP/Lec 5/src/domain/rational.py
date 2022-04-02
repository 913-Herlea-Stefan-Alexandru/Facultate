'''
Class rational
'''

class rational:
    """
    This is the rational data type
    Data type = domain + operations
        domain - means the set of attributes and possible values
        operations - means methods
    """
    def __init__(self, numerator=0, denominator=1):
        self.numerator = numerator
        self.denominator = denominator

    @property
    def numerator(self):
        return self.__numerator

    @property
    def denominator(self):
        return self.__denominator

    @numerator.setter
    def numerator(self, value):
        self.__numerator = value

    @denominator.setter
    def denominator(self, value):
        if value == 0:
            raise ValueError('rational cannot have 0 denominator')
        self.__denominator = value



q1 = rational(9) # this calls __init__
q1.numerator += 1
print(q1.numerator)

'''
V1
    + looks nice
    - breaks encapsulation
'''
#q1.numerator += 1

'''
V2
    - not nice
    + works ok
'''
#q1.set_numerator(q1.get_numerator() + 1)

'''
V3
    + looks nice
    + works correctly
'''

# q1.get_numerator() <==> rational.get_numerator(q1)




# q1.denominator = 0
# just because you can doesn't mean ...
# q1.__denominator = 0


#print(q1)


# q2 = rational()

# print(q1)
# print(q1.numerator)
# print(q1.denominator)