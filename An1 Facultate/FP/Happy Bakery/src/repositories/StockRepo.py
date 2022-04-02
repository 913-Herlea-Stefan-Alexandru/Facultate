from domain.stock import Stock


class StockRepository:
    """
    This is where we manage bakery stocks
    """
    def __init__(self):
        self._data = {}

    def get(self, item_name):
        return self._data[item_name]

    def add(self, stock_item):
        """
        Add the new stock item. If it already exists, than its quantity is increased
        :param stock_item:
        :return: -
        """
        if not isinstance(stock_item, Stock):
            raise TypeError('Not a stock item!')

        # Check stock item is unique
        if stock_item.name in self._data:
            self._data[stock_item.name].quantity += stock_item.quantity
        else:
            self._data[stock_item.name] = stock_item

    def __getitem__(self, key):
        return self._data[key]

    def __len__(self):
        return len(self._data)



def test_stock_repo():
    sr = StockRepository()

    # No stock items in repo
    assert len(sr) == 0

    sr.add(Stock('White Flour 558', 100))
    assert len(sr) == 1

    assert sr['White Flour 558'] == Stock('White Flour 558', 100)

    sr.add(Stock('White Flour 558', 100))
    assert sr['White Flour 558'].quantity == 200


test_stock_repo()