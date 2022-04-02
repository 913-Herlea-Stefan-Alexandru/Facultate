from domain.number import NumberValidator
from functions.operations import Operations
from functions.converters import Converters
from functions.number_creator import Creator
from console.menu_ui import MenuUI

if __name__ == '__main__':
    nval = NumberValidator()
    creator = Creator(nval)
    operations = Operations(nval)
    converter = Converters()
    ui = MenuUI(operations, converter, creator)
    ui.start()