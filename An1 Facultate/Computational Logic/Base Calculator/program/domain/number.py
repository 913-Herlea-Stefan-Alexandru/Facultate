class NumberError(Exception):
    def __init__(self, msg):
        self._msg = msg

class Number:
    def __init__(self, base, number):
        self._base = base
        self._number = number

    @property
    def number(self):
        return self._number

    @property
    def base(self):
        return self._base

    def __len__(self):
        return len(self.number)

    def __add__(self, other):
        '''
        Adds two numbers together by adding each digit of each number from the right and keeping a carry if necessary
        :param other: the other number (Number object)
        :return: the result of the operation
        :raises: NumberError if the 'other' parameter is not of type Number or if the numbers don't have the same base
        '''
        if type(other) != type(self):
            raise NumberError('Cannot add a non number to a number')
        if self.base != other.base:
            raise NumberError('Cannot add two numbers of different bases')
        result = ''
        carry = 0
        number1 = self.number[::-1]
        number2 = other.number[::-1]
        for index in range(max(len(number1), len(number2))):
            digit_sum = carry
            if len(number1) <= index:
                pass
            elif '0' <= number1[index] <= '9':
                digit_sum += int(number1[index])
            else:
                digit_sum += (ord(number1[index])-55)
            if len(number2) <= index:
                pass
            elif '0' <= number2[index] <= '9':
                digit_sum += int(number2[index])
            else:
                digit_sum += (ord(number2[index])-55)
            carry = int(digit_sum/self.base)
            digit = digit_sum%self.base
            if 10 <= digit:
                digit = chr(digit+55)
            result += str(digit)
        if carry != 0:
            result += str(carry)
        return Number(self.base, result[::-1])

    def __mul__(self, other):
        '''
        Multiplies two numbers together by multiplying each digit of the first number from the right with the second
        number and keeps a carry if necessary
        :param other: the other number (Number object)
        :return: the result of the operation
        :raises: NumberError if the 'other' parameter is not of type Number, if the numbers don't have the same base
        or if the 'other' number has more than one digit
        '''
        if type(other) != type(self):
            raise NumberError('Cannot multiply a non number to a number')
        if self.base != other.base:
            raise NumberError('Cannot multiply two numbers of different bases')
        if len(other.number) != 1:
            raise NumberError('Cannot multiply by more than one digit')
        result = ''
        carry = 0
        number1 = self.number[::-1]
        number2 = other.number
        if 'A' <= number2:
            number2 = (ord(number2) - 55)
        else:
            number2 = int(number2)
        for index in range(len(number1)):
            digit_product = 1
            if '0' <= number1[index] <= '9':
                digit_product *= int(number1[index])
            else:
                digit_product *= (ord(number1[index])-55)
            digit_product *= number2
            digit_product += carry
            carry = int(digit_product/self.base)
            digit = digit_product%self.base
            if 10 <= digit:
                digit = chr(digit+55)
            result += str(digit)
        if carry != 0:
            if 10 <= carry:
                carry = chr(carry+55)
            result += str(carry)
        return Number(self.base, result[::-1])

    def __lt__(self, other):
        if len(self) < len(other):
            return True
        elif len(other) < len(self):
            return False
        index = len(self) - 1
        while index >= 0 and self.number[index] == other.number[index]:
            index -= 1
        if self.number[index] < other.number[index]:
            return True
        else:
            return False

    def __sub__(self, other):
        '''
        Subtracts two numbers by subtracting each digit of each number from the right and keeping a remainder if necessary
        :param other: the other number (Number object)
        :return: the result of the operation
        :raises: Number error if the 'other' parameter is not of type Number, if the numbers don't have the same base
        or if the second number is larger than the first one
        '''
        if type(other) != type(self):
            raise NumberError('Cannot subtract a non number to a number')
        if self.base != other.base:
            raise NumberError('Cannot subtract two numbers of different bases')
        if self < other:
            raise NumberError('Cannot subtract a smaller number from a larger number')
        result = ''
        transport = 0
        number1 = self.number[::-1]
        number2 = other.number[::-1]
        for index in range(len(number1)):
            digit_dif = 0
            if '0' <= number1[index] <= '9':
                digit_dif += int(number1[index])
            else:
                digit_dif += (ord(number1[index]) - 55)
            if index >= len(number2):
                digit_dif -= 0
            elif '0' <= number2[index] <= '9':
                digit_dif -= int(number2[index])
            else:
                digit_dif -= (ord(number2[index]) - 55)
            digit_dif += transport
            if digit_dif < 0:
                transport = -1
                digit_dif += self.base
            else:
                transport = 0
            if digit_dif <= 9:
                result += str(digit_dif)
            else:
                result += chr(digit_dif + 55)
        index = 0
        result = result[::-1]
        while index < len(result) - 1 and result[index] == '0':
            result = result[index+1:]
        return Number(self._base, result)

    def __truediv__(self, other):
        '''
        Divides two numbers by taking each digit from the first number from left and divide it by the second number,
        keeping a remainder if necessary
        :param other: the other number (Number object)
        :return: the result of the operation
        :raises: Number error if the 'other' parameter is not of type Number, if the numbers don't have the same base,
        if the second number has more than one digit or if the second number is 0
        '''
        if type(other) != type(self):
            raise NumberError('Cannot divide a non number to a number')
        if self.base != other.base:
            raise NumberError('Cannot divide two numbers of different bases')
        if len(other.number) != 1:
            raise NumberError('Cannot divide by more than one digit')
        if other.number == '0':
            raise NumberError('Cannot divide by 0')
        quotient = ''
        index = 0
        dividend = self.number[index]
        if dividend < other.number and index + 1 < len(self):
            index += 1
            dividend += self.number[index]
        divisor = (int(other.number) if '0' <= other.number <= '9' else (ord(other.number) - 55))
        while index < len(self.number):
            if len(dividend) <= 1:
                d = (int(dividend) if '0' <= dividend <= '9' else (ord(dividend) - 55))
            else:
                d = (int(dividend[1]) if '0' <= dividend[1] <= '9' else (ord(dividend[1]) - 55))
                d += self.base * (int(dividend[0]) if '0' <= dividend[0] <= '9' else (ord(dividend[0]) - 55))
            q = d // divisor
            r = d % divisor
            quotient += (str(q) if 0 <= q <= 9 else chr(q + 55))
            dividend = (str(r) if 0 <= r <= 9 else chr(r + 55))
            if index + 1 < len(self):
                index += 1
                dividend += self.number[index]
            else:
                break
        remainder = dividend
        return Number(self.base, quotient), remainder

    def __str__(self):
        return self._number + '(' + str(self._base) + ')'




class NumberValidator:
    def __init__(self):
        pass

    def validate(self, number):
        '''
        Checks if a number is valid
        :param number: the given number (Number object)
        :return: -
        :raises: NumberError if the type of number.number is not string, if the type of the number.base is not integer,
        if the base is not between 2 and 16, if the number is empty or if any digit from the number is larger than or
        equal to the base
        '''
        if type(number.number) != type(''):
            raise NumberError('Wrong type for number')
        if type(number.base) != type(1):
            raise NumberError('Wrong type for base')
        if not (2 <= number.base <= 10 or number.base == 16):
            raise NumberError('Base must be between 2 and 16')
        if number.number == '':
            raise NumberError('No number was entered')
        for digit in number.number:
            if '0' <= digit <= '9':
                digit = int(digit)
            else:
                digit = (ord(digit)-55)
            if digit >= number.base:
                raise NumberError('The number cannot have digits larger than or equal to the base of origin')




def test_number_add():
    number1 = Number(2, '101001111')
    number2 = Number(2, '1110110')
    number3 = number1 + number2
    assert str(number3) == '111000101(2)'
    number1 = Number(16, 'FAD467')
    number2 = Number(16, '321ABED9')
    number3 = number1 + number2
    assert str(number3) == '33159340(16)'
    try:
        Number(2, '100111')+110101
        assert False
    except NumberError:
        assert True
    try:
        Number(2, '110011') + Number(3, '1112021')
        assert False
    except NumberError:
        assert True

def test_number_mul():
    number1 = Number(8, '364701')
    number2 = Number(8, '7')
    number3 = number1*number2
    assert str(number3) == '3262107(8)'
    try:
        Number(2, '100111')*Number(2, '101')
        assert False
    except NumberError:
        assert True

def test_number_sub():
    number1 = Number(2, '10001111')
    number2 = Number(2, '1110101')
    number3 = number1 - number2
    assert str(number3) == '11010(2)'
    try:
        Number(2, '111') - Number(2, '11111')
        assert False
    except NumberError:
        assert True

def test_number_div():
    number1 = Number(6, '3543')
    number2 = Number(6, '5')
    number3, reminder = number1 / number2
    assert str(number3) == '443(6)' and reminder == '0'

if __name__ == '__main__':
    test_number_add()
    test_number_mul()
    test_number_sub()
    test_number_div()