from repositories.TextRepo import TextRepo
from entities.player import Player
from utility.functions import Functions
from ui.menu_ui import MenuUI

if __name__ == '__main__':
    repo = TextRepo('PlayerFile', Player)
    functions = Functions(repo)
    ui = MenuUI(functions)
    ui.start()