from domain.number import NumberValidator, Number

class Creator:
    def __init__(self, validator):
        self._validator = validator

    def create(self, base, number):
        '''
        Validates and creates a number with the given parameters
        :param base: the base of the number (int)
        :param number: the number (str)
        :return: the number (Number object)
        '''
        self._validator.validate(Number(base, number))
        return Number(base, number)