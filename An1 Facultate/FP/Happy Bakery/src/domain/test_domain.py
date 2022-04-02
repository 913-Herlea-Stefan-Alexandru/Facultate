import unittest
from domain.ingredient import Ingredient


class IngredientTest(unittest.TestCase):
    def test_ingr(self):
        ingr = Ingredient(100, 'Vanilla', 100)
        self.assertEqual(ingr.id, 100)
        self.assertEqual(ingr.name, 'Vanilla')
        self.assertEqual(ingr.price, 100)

    def test_ingr2(self):
        self.assertFalse('nope')
