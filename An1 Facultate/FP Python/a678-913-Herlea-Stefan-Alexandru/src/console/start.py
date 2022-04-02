from src.console.UI import MenuUI
from src.console.GUI import GUI
from src.tests.PyUnit import test_init, test2_init
from src.services.services import Service
from src.validators.validator import Validation
from src.repositories.StudentRepository import StudentRepository
from src.repositories.DisciplineRepository import DisciplineRepository
from src.repositories.GradeRepository import GradeRepository
from src.services.undoService import UndoService

if __name__ == '__main__':
    val = Validation()
    undo = UndoService()
    stud_repo = StudentRepository()
    disc_repo = DisciplineRepository()
    grade_repo = GradeRepository()
    sv = Service(stud_repo, disc_repo, grade_repo, val, undo)
    while True:
        print('Start the program with: ')
        print('1. Randomized values')
        print('2. Predefined values')
        choice = input('Choice: ')
        if choice == '1':
            test_init(stud_repo, disc_repo, grade_repo)
            break
        elif choice == '2':
            test2_init(stud_repo, disc_repo, grade_repo)
            break
        else:
            print('Invalid choice\n')
    while True:
        print('Start the program with: ')
        print('1. Console UI')
        print('2. Graphical UI')
        choice = input('Choice: ')
        if choice == '1':
            UI = MenuUI(sv)
            break
        elif choice == '2':
            UI = GUI(sv)
            break
        else:
            print('Invalid choice\n')
    UI.start()