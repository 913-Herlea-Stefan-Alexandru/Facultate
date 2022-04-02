"""
    Service class includes functionalities for implementing program features
"""
import string

from src.domain.entity import Book
from src.repository.BookRepo import BookRepository, RepoError
import random


class ServiceError(Exception):
    def __init__(self, msg):
        self._msg = msg

class Services:

    def __init__(self, book_repo):
        '''
        The constructor which creates the list of books and a list for the undo operation
        '''
        self._repo = book_repo

    def test_init(self):
        i = 0
        while i < 10:
            letter = string.ascii_lowercase
            r = random.randint(5, 9)
            isbn = ''.join(str(random.randint(5, 8)) for i in range(r))
            r = random.randint(4, 15)
            author = ''.join(random.choice(letter) for i in range(r))
            author = author[:int((len(author))/2)] + ' ' + author[int((len(author))/2):]
            r = random.randint(4, 30)
            title = ''.join(random.choice(letter) for i in range(r))
            title = title[:int((len(title)) / 2)] + ' ' + title[int((len(title)) / 2):]
            try:
                self._repo + Book(isbn, author, title)
            except RepoError:
                i -= 1
            i += 1


    def add_book(self, book):
        '''
        Adds a book to the current list of books. It also copies the last known instance of the list to the undo list
        :param book: the book: Book()
        :return: -
        Raises ServiceError if the book isbn is already in the list
        '''
        self._repo + book

    def first_word(self, title):
        '''
        Splits the title and returns the first word of it
        :param title: the title
        :return: the first word of the title
        '''
        tokens = title.strip().split(' ', 1)
        return tokens[0]

    def filter(self, word):
        '''
        Checks if the first word of each title is the given one and deletes the book from the list if so
        :param word: the given word
        :return: -
        Raises ServiceError if the book is not found
        '''
        index = 0
        ok = False
        self._repo.undo_list.append(self._repo.book_list.copy())
        while index < len(self):
            if word.lower() == self.first_word(self._repo.book_list[index].title).lower():
                self._repo.book_list.pop(index)
                index -= 1
                ok = True
            index += 1
        if not ok:
            self._repo.undo_list.pop()
            raise ServiceError('\nNo book found')

    def undo(self):
        '''
        Reverts the last operation that modified the list
        :return:
        Raises ServiceError if the list is empty
        '''
        if self._repo.undo_list == []:
            raise ServiceError('\nNothing to undo')
        self._repo.book_list = self._repo.undo_list.pop()

    def __len__(self):
        return len(self._repo)

    def to_str(self):
        '''
        Transforms he list of books into a readable string
        :return: the readable string
        '''
        str_list = ''
        for book in self._repo.book_list:
            str_list += book.to_str() + '\n'
        return str_list


def test_add():
     repo = BookRepository()
     s = Services(repo)
     b1 = Book('gg', 'Eminescu', 'Luceafarul')
     s.add_book(b1)
     assert len(s) == 1
     b2 = Book('gg', 'wegwe', 'wegw')
     try:
         s.add_book(b2)
         assert False
     except RepoError:
         assert True
     b3 = Book('alh', 'wegwe', 'wegw')
     s.add_book(b3)
     assert len(s) == 2

def test_filter():
    repo = BookRepository()
    s = Services(repo)
    s.test_init()
    s.filter('Amintiri')
    assert len(s) == 3
    try:
        s.filter('Park')
        assert False
    except ServiceError:
        assert True

def test_undo():
    repo = BookRepository()
    s = Services(repo)
    s.test_init()
    s.undo()
    assert len(s) == 3 and s._repo.book_list[2].isbn == '11923'
    for i in range(3):
        s.undo()
    assert len(s) == 0
    try:
        s.undo()
        assert False
    except ServiceError:
        assert True

if __name__ == '__main__':
    test_add()
    test_undo()
    test_filter()