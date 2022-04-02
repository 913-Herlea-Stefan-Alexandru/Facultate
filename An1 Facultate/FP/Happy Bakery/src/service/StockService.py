from repositories.StockRepo import StockRepository


class StockService:
    """
    Manage functionalities related with existing stock
    """
    def __init__(self, stock_repo):
        """

        :param stock_repo:
            This tells 2 things:
                1. StockService can't do it's job without access to a StackRepository object
                2. Allows you to change the implementation of the repo
                    (modules are independent AND interchangeable)
        """
        self._repo = stock_repo

    def add(self, stock_item):
        pass

    def find(self, string):
        pass

    def get_all(self):
        pass



def test_stock_service():
    # TODO Implement more tests
    repo = StockRepository()
    service = StockService(repo)

# test_stock_service()
print(help(StockRepository))