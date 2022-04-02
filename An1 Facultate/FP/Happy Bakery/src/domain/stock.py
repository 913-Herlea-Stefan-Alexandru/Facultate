class Stock:
    """
    Represent a unit of stock that we need or have available
    """

    # TODO How do we know name is str (Ingredient) or a Product
    def __init__(self, name, quantity):
        if len(name) < 3:
            raise ValueError('Stock item name too short')

        # Not really required, but not wrong either
        if not isinstance(quantity, int):
            raise TypeError('Stock quantity must be int')

        self._name = name
        self.quantity = quantity

    '''
    Read-only property - does not have a setter
    '''
    @property
    def name(self):
        return self._name

    @property
    def quantity(self):
        return self._quantity

    @quantity.setter
    def quantity(self, value):
        if value < 1:
            raise ValueError('Stock quantity must be >0')
        self._quantity = value

    def __eq__(self, other):
        if not isinstance(other, Stock):
            return False

        return self.name == other.name and self.quantity == other.quantity


def test_stock():
    # TODO Test quantity field
    s = Stock('White Flour 558', 100)
    assert 'White Flour 558' == s.name
    try:
        s.name = 'Other kind of flour'
        assert False, 'This should be read-only'
    except AttributeError:
        assert True

test_stock()