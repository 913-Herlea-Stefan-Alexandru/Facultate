from domain.number import NumberError
from functions.converters import ConversionError

class MenuUI:
    def __init__(self, operations, converter, creator):
        self._operations = operations
        self._converter = converter
        self._creator = creator

    def menu(self):
        print('\n1. Add two numbers')
        print('2. Subtract two numbers')
        print('3. Multiply a number by a digit')
        print('4. Divide a number by a digit')
        print('5. Successive divisions method')
        print('6. Substitution method')
        print('7. Intermediary base method')
        print('8. Rapid conversions')
        print('x. Exit\n')

    def add_ui(self):
        base = input('Enter the base for the operation: ')
        try:
            base = int(base)
        except:
            raise NumberError('Base has to be an integer')
        number1 = input('Enter the first number in base ' + str(base) + ': ')
        number2 = input('Enter the second number in base ' + str(base) + ': ')
        print(self._operations.add(base, number1, number2))

    def sub_ui(self):
        base = input('Enter the base for the operation: ')
        try:
            base = int(base)
        except:
            raise NumberError('Base has to be an integer')
        number1 = input('Enter the first number in base ' + str(base) + ': ')
        number2 = input('Enter the second number in base ' + str(base) + ': ')
        print(self._operations.sub(base, number1, number2))

    def mul_ui(self):
        base = input('Enter the base for the operation: ')
        try:
            base = int(base)
        except:
            raise NumberError('Base has to be an integer')
        number1 = input('Enter the first number in base ' + str(base) + ': ')
        number2 = input('Enter the second number in base ' + str(base) + ': ')
        print(self._operations.mul(base, number1, number2))

    def div_ui(self):
        base = input('Enter the base for the operation: ')
        try:
            base = int(base)
        except:
            raise NumberError('Base has to be an integer')
        number1 = input('Enter the first number in base ' + str(base) + ': ')
        number2 = input('Enter the second number in base ' + str(base) + ': ')
        result, remainder = self._operations.div(base, number1, number2)
        print(result, ' remainder: ', remainder)

    def conv_div_ui(self):
        base1 = input('Enter the base of origin: ')
        try:
            base1 = int(base1)
        except:
            raise NumberError('Base has to be an integer')
        number = input('Enter the number to convert from base ' + str(base1) + ': ')
        base2 = input('Enter the destination base: ')
        try:
            base2 = int(base2)
        except:
            raise NumberError('Base has to be an integer')
        print(self._converter.successive_div(self._creator.create(base1, number), base2))

    def conv_sub_ui(self):
        base1 = input('Enter the base of origin: ')
        try:
            base1 = int(base1)
        except:
            raise NumberError('Base has to be an integer')
        number = input('Enter the number to convert from base ' + str(base1) + ': ')
        base2 = input('Enter the destination base: ')
        try:
            base2 = int(base2)
        except:
            raise NumberError('Base has to be an integer')
        print(self._converter.substitution(self._creator.create(base1, number), base2))

    def conv_inter_ui(self):
        base1 = input('Enter the base of origin: ')
        try:
            base1 = int(base1)
        except:
            raise NumberError('Base has to be an integer')
        number = input('Enter the number to convert from base ' + str(base1) + ': ')
        base2 = input('Enter the destination base: ')
        try:
            base2 = int(base2)
        except:
            raise NumberError('Base has to be an integer')
        print(self._converter.intermediate_base(self._creator.create(base1, number), base2))

    def conv_rapid_ui(self):
        base1 = input('Enter the base of origin: ')
        try:
            base1 = int(base1)
        except:
            raise NumberError('Base has to be an integer')
        number = input('Enter the number to convert from base ' + str(base1) + ': ')
        base2 = input('Enter the destination base: ')
        try:
            base2 = int(base2)
        except:
            raise NumberError('Base has to be an integer')
        print(self._converter.rapid_conversions(self._creator.create(base1, number), base2))

    def start(self):
        is_running = True
        command_dict = {'1': self.add_ui, '2': self.sub_ui, '3': self.mul_ui, '4': self.div_ui, '5': self.conv_div_ui,
                        '6': self.conv_sub_ui, '7': self.conv_inter_ui, '8': self.conv_rapid_ui}
        while is_running:
            self.menu()
            command = input('Choose an option: ')
            if command in command_dict:
                try:
                    command_dict[command]()
                except (NumberError, ConversionError) as err:
                    print(str(err))
            elif command == 'x':
                is_running = False
            else:
                print('\nInvalid command\n')