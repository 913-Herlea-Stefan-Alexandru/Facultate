"""
- Implement a new repository thet is able to persist data to text files
- Keep the functionalities from Repository class (code reuse, don't write things twice,
    swap the memory-repo with the text-repo) -> modules are independent and interchangeable
"""
from domain.ingredient import Ingredient
from repositories.repository import Repository


class IngredientTextFileRepository(Repository):
    """
    Inheritance -> TextFileRepository is a Repository

    What we want:
        1. TextFileRepository behaves EXACTLY like Repository
            with one exception
        2. Ingredients are saved to/loaded from a text file
    """
    def __init__(self, file_name = 'ingredients.txt'):
        super().__init__()
        self._file_name = file_name
        self._load()

    def store(self, item):
        super().store(item)
        self._save()

    def delete(self, id_):
        super().delete(id_)
        self._save()

    def _save(self):
        f = open(self._file_name, 'wt')
        for ingr in self._data:
            line = str(ingr.id) + ';' + ingr.name + ';' + str(ingr.price)
            f.write(line)
            f.write('\n')
        f.close()

    def _load(self):
        f = open(self._file_name, 'rt')
        lines = f.readlines()
        f.close()

        for line in lines:
            line = line.split(';')
            super().store(Ingredient(int(line[0]), line[1], int(line[2])))