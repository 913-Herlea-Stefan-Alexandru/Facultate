import unittest

from domain.ingredient import Ingredient
from repositories.repository import Repository, RepositoryException


class TestRepo(unittest.TestCase):
    def setUp(self):
        """
        Runs before each test method
        """
        self._repo = Repository()
        self._repo.store(Ingredient(100, "Bread Flour (White, 550)", 1))
        self._repo.store(Ingredient(101, "Yeast (dry)", 15))
        self._repo.store(Ingredient(102, "Sugar (white)", 24))
        self._repo.store(Ingredient(103, "Salt (regular)", 30))


    def test_repo_store(self):
        self.assertEqual(len(self._repo), 4)
        self.assertRaises(RepositoryException, self._repo.store, Ingredient(103, 'Salt (regular)', 10))

    def test_repo_find(self):
        self.assertFalse('no bueno')

    def test_repo_delete(self):
        self.assertFalse('no bueno')

    def tearDown(self):
        """
        Runs after each test method
        """
        print('TORE DOWN')