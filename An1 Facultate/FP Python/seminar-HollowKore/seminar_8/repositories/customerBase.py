from seminar_8.validators.clientValidator import CarRentalException
from seminar_8.entities.client import Client

class CustomerBase:
    def __init__(self):
        self._clients = []

    def remove(self, given_id):
        for client in self._clients:
            if client.client_id == given_id:
                self._clients.pop(self._clients.index(client))
                return
        raise CarRentalException('No client with given id found')

    def search(self, search_str = ''):
        found = []
        for client in self._clients:
            if search_str in client.client_id or search_str in client.name:
                found.append(client)
        if found == []:
            raise CarRentalException('No client found')
        return found

    def add(self, client):
        if client.client_id in [c.client_id for c in self._clients]:
            raise CarRentalException('Client id already in database')
        self._clients.append(client)

    def __len__(self):
        return len(self._clients)



def test_customer_base_init(base):
    base.add(Client('12345', 'Dan Marc', 25))
    base.add(Client('23523', 'Bob Gog', 18))
    base.add(Client('26667', 'Dan Greg', 71))
    base.add(Client('74776', 'Josh Marc', 60))
    base.add(Client('24235', 'Doc', 33))
    base.add(Client('58568', 'Olga', 22))
    base.add(Client('12314', 'Ben ', 19))
    base.add(Client('26547', 'Kevin Moris', 43))

def test_customer_base():
    base = CustomerBase()
    test_customer_base_init(base)
    assert len(base) == 8
    base.remove('26667')
    assert len(base) == 7
    try:
        base.remove('99999')
        assert False
    except CarRentalException:
        assert True

if __name__ == '__main__':
    test_customer_base()
