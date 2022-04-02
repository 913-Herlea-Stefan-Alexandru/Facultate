"""
    UI class.

    Calls between program modules
    ui -> service -> entity
    ui -> entity
"""
from src.domain.entity import Book
from src.repository.BookRepo import BookRepository, RepoError
from src.services.service import Services, ServiceError


class Books_UI:

    def __init__(self, repo):
        self._services = Services(repo)
        self._is_running = True
        self._command_dict = {'1': self.add, '2': self.print, '3': self.filter, '4': self.undo}
        self._services.test_init()

    def print_menu(self):
        print('\n1. Add a book.')
        print('2. Display the list of books.')
        print('3. Filter the list so that book titles starting with a given word are deleted from the list.')
        print('4. Undo the last operation that modified program data.')
        print('x. Exit\n')

    def print(self):
        print(self._services.to_str())

    def undo(self):
        self._services.undo()

    def filter(self):
        word = input('Enter the first word of the title: ')
        print()
        self._services.filter(word)
        self.print()

    def add(self):
        isbn = input('Enter book\'s isbn: ')
        auth = input('Enter book\'s author: ')
        title = input('Enter book\'s title: ')
        self._services.add_book(Book(isbn, auth, title))

    def start(self):
        while self._is_running:
            self.print_menu()
            command = input('Enter option: ')
            if command in self._command_dict:
                try:
                    self._command_dict[command]()
                except ServiceError as se:
                    print(str(se))
                except RepoError as re:
                    print(str(re))
            elif command == 'x':
                self._is_running = False
            else:
                print('\nInvalid option')

if __name__ == '__main__':
    repo = BookRepository()
    UI = Books_UI(repo)
    UI.start()