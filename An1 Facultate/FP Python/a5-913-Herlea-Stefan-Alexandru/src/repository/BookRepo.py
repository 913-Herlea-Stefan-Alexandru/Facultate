from src.domain.entity import Book

class RepoError(Exception):
    def __init__(self, msg):
        self._msg = msg

class BookRepository:

    def __init__(self):
        self._book_list = []
        self._undo_list = []

    @property
    def book_list(self):
        return self._book_list

    @book_list.setter
    def book_list(self, value):
        self._book_list = value.copy()

    @property
    def undo_list(self):
        return self._undo_list

    @undo_list.setter
    def undo_list(self, value):
        self._undo_list = value.copy()

    def __len__(self):
        return len(self.book_list)

    def __add__(self, book):
        if not isinstance(book, Book):
            raise RepoError('\nCan only add books')
        if book.isbn in [b.isbn for b in self.book_list]:
            raise RepoError('\nBook already in the list')
        self.undo_list.append(self.book_list.copy())
        self.book_list.append(book)