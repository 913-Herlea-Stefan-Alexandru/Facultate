from domain.number import Number, NumberValidator, NumberError

class Operations:
    def __init__(self, number_validator):
        self._validator = number_validator

    def add(self, base, number1, number2):
        '''
        Adds number1 and number2
        :param base: the base of the numbers (int)
        :param number1: the first number (str)
        :param number2: the second number (str)
        :return: number1 + number2 (Number object)
        '''
        self._validator.validate(Number(base, number1))
        self._validator.validate(Number(base, number2))
        number3 = Number(base, number1) + Number(base, number2)
        return number3

    def mul(self, base, number1, number2):
        '''
        Multiplies number1 by number2
        :param base: the base of the numbers (int)
        :param number1: the first number (str)
        :param number2: the second number (str)
        :return: number1 * number2 (Number object)
        '''
        self._validator.validate(Number(base, number1))
        self._validator.validate(Number(base, number2))
        number3 = Number(base, number1) * Number(base, number2)
        return number3

    def sub(self, base, number1, number2):
        '''
        Subtracts number1 and number2
        :param base: the base of the numbers (int)
        :param number1: the first number (str)
        :param number2: the second number (str)
        :return: number1 - number2 (Number object)
        '''
        self._validator.validate(Number(base, number1))
        self._validator.validate(Number(base, number2))
        number3 = Number(base, number1) - Number(base, number2)
        return number3

    def div(self, base, number1, number2):
        '''
        Divides number1 by number2
        :param base: the base of the numbers (int)
        :param number1: the first number (str)
        :param number2: the second number (str)
        :return: number1 / number2 (Number object)
        '''
        self._validator.validate(Number(base, number1))
        self._validator.validate(Number(base, number2))
        number3, remainder = Number(base, number1) / Number(base, number2)
        return number3, remainder




def test_add():
    nval = NumberValidator()
    op = Operations(nval)
    number = op.add(2, '101001111', '1110110')
    assert str(number) == '111000101(2)'
    number = op.add(16, 'FAD467', '321ABED9')
    assert str(number) == '33159340(16)'
    try:
        op.add(1, '00000', '00000')
        assert False
    except NumberError:
        assert True
    try:
        op.add(3, '2341', '1124')
        assert False
    except NumberError:
        assert True

def test_mul():
    nval = NumberValidator()
    op = Operations(nval)
    number = op.mul(8, '364701', '7')
    assert str(number) == '3262107(8)'

def test_sub():
    nval = NumberValidator()
    op = Operations(nval)
    number = op.sub(16, 'FAC32', 'D45C')
    assert str(number) == 'ED7D6(16)'


if __name__ == '__main__':
    test_add()
    test_mul()
    test_sub()
