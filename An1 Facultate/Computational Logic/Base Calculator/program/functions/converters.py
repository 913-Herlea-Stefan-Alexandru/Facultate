from domain.number import Number


class ConversionError(Exception):
    def __init__(self, msg):
        self._msg = msg


class Converters:
    def __init__(self):
        pass

    def successive_div(self, number, base2):
        '''
        Converts a number to the destination base using successive divisions
        :param number: the number to convert (Number object)
        :param base2: the base to convert the number to (int)
        :return: the converted number
        '''
        if number.base == 10:
            result = ''
            number_int = int(number.number)
            while number_int != 0:
                quotient = number_int // base2
                remainder = number_int % base2
                if remainder <= 9:
                    result += str(remainder)
                else:
                    result += chr(remainder + 55)
                number_int = quotient
            return Number(base2, result[::-1])
        else:
            result = ''
            number_str = number.number
            base2_str = (str(base2) if base2 <= 9 else chr(base2 + 55))
            while number_str != '0':
                quotient = ''
                index = 0
                dividend = number_str[index]
                if dividend < base2_str and index + 1 < len(number_str):
                    index += 1
                    dividend += number_str[index]
                divisor = base2
                while index < len(number_str):
                    if len(dividend) <= 1:
                        d = (int(dividend) if '0' <= dividend <= '9' else (ord(dividend) - 55))
                    else:
                        d = (int(dividend[1]) if '0' <= dividend[1] <= '9' else (ord(dividend[1]) - 55))
                        d += number.base * (int(dividend[0]) if '0' <= dividend[0] <= '9' else (ord(dividend[0]) - 55))
                    q = d // divisor
                    r = d % divisor
                    quotient += (str(q) if 0 <= q <= 9 else chr(q + 55))
                    dividend = (str(r) if 0 <= r <= 9 else chr(r + 55))
                    if index + 1 < len(number_str):
                        index += 1
                        dividend += number_str[index]
                    else:
                        break
                remainder = dividend
                result += remainder
                number_str = quotient
            while result[len(result) - 1] == '0':
                result = result[:-1]
            return Number(base2, result[::-1])

    def intermediate_base(self, number, base2):
        '''
        Converts a number to the destination base using an intermediary base (10)
        :param number: the number to convert (Number object)
        :param base2: the base to convert the number to (int)
        :return: the converted number
        '''
        number_base10 = self.substitution(number, 10)
        number_destination_base = self.successive_div(number_base10, base2)
        return number_destination_base

    def substitution(self, number, base2):
        '''
        Converts a number to the destination base using the substitution method
        :param number: the number to convert (Number object)
        :param base2: the base to convert the number to (int)
        :return: the converted number
        '''
        if base2 == 10:
            result = 0
            number_inv = number.number[::-1]
            for poz in range(len(number)):
                if '0' <= number_inv[poz] <= '9':
                    digit = int(number_inv[poz])
                else:
                    digit = ord(number_inv[poz]) - 55
                result += digit * pow(number.base, poz)
            result = str(result)
            return Number(base2, result)
        else:
            result = Number(base2, '0')
            number_inv = number.number[::-1]
            for poz in range(len(number)):
                if '0' <= number_inv[poz] <= '9':
                    digit = int(number_inv[poz])
                else:
                    digit = ord(number_inv[poz]) - 55
                result += self.successive_div(Number(10, str(digit * pow(number.base, poz))), base2)
            return result

    def rapid_conversions(self, number, base2):
        '''
        Converts a number to the destination base using rapid conversions
        :param number: the number to convert (Number object)
        :param base2: the base to convert the number to (int)
        :return: the converted number
        '''
        if number.base == 2 and base2 not in [4, 8, 16]:
            raise ConversionError('Rapid conversions can only be done from base 2 into bases 4, 8, 16 and vice versa')
        if base2 == 2 and number.base not in [4, 8, 16]:
            raise ConversionError('Rapid conversions can only be done from base 2 into bases 4, 8, 16 and vice versa')
        if number.base == 2:
            result = ''
            r_base2 = base2
            p = 0
            while r_base2 != 1:
                r_base2 //= 2
                p += 1
            nr = number.number
            while len(nr) % p != 0:
                nr = '0' + nr
            while len(nr) != 0:
                result += self.substitution(Number(2, nr[:p]), base2).number
                nr = nr[p:]
            return Number(base2, result)
        else:
            result = ''
            r_base = number.base
            p = 0
            while r_base != 1:
                r_base //= 2
                p += 1
            for index in range(len(number)):
                digit = self.substitution(Number(base2, number.number[index]), 2).number
                if index != 0:
                    while len(digit) % p != 0:
                        digit = '0' + digit
                result += digit
            return Number(2, result)


def test_div():
    c = Converters()
    number = c.successive_div(Number(10, '74583'), 16)
    assert str(number) == '12357(16)'


def test_substitution():
    c = Converters()
    number = c.substitution(Number(16, 'F3CD2'), 10)
    assert str(number) == '998610(10)'
    number = c.substitution(Number(9, '37253'), 6)
    assert str(number) == '311420(6)'


def test_intermediate_base():
    c = Converters()
    number = c.intermediate_base(Number(5, '413'), 7)
    assert str(number) == '213(7)'


def test_rapid():
    c = Converters()
    number = c.rapid_conversions(Number(2, '101111111010'), 16)
    assert str(number) == 'BFA(16)'
    number = c.rapid_conversions(Number(8, '2324'), 2)
    assert str(number) == '10011010100(2)'


if __name__ == '__main__':
    test_div()
    test_substitution()
    test_intermediate_base()
    test_rapid()