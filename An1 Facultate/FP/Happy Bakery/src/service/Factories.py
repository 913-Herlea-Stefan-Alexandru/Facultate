from domain.ingredient import Ingredient


class IngredientFactory:
    """
    Create validated instances of Ingredient
    """
    def __init__(self, validator):
        self._validator = validator

    def create_ingredient(self, id_, name, price):
        ingr = Ingredient(id_, name, price)
        self._validator.validate(ingr)
        return ingr