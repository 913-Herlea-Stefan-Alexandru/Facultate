"""
    Entity class should be coded here
"""

class Book:

    def __init__(self, isbn, author, title):
        self._isbn = isbn
        self._author = author
        self._title = title

    @property
    def isbn(self):
        return self._isbn

    @isbn.setter
    def isbn(self, value):
        self._isbn = value

    @property
    def author(self):
        return self._author

    @author.setter
    def author(self, value):
        self._author = value

    @property
    def title(self):
        return self._title

    @title.setter
    def title(self, value):
        self._title = value

    def to_str(self):
        return self.isbn.ljust(10) + self.author.ljust(20) + self.title