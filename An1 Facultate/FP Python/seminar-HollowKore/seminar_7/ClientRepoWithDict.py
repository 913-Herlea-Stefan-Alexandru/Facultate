class ClientRepoWithDict:
    def __init__(self):
        self._clients = {}

    def add(self, client):
        if client.client_id in self._clients:
            raise ValueError('Client with id already in list')
        self._clients[client.id] = client

    def remove(self, client_id):
        if client_id in self._clients:
            self._clients.pop(client_id)
        else:
            raise ValueError('Client not found')

    def get_all(self):
        return [self._clients[client_id] for client_id in self._clients]

def test_client_repo_init(client_repo):
    client_repo.add(Client('1111111111', 'Bob', 27))
    client_repo.add(Client('2222222222', 'Dan', 35))
    client_repo.add(Client('3333333333', 'Roger', 23))
    client_repo.add(Client('4444444444', 'George', 22))
    client_repo.add(Client('5555555555', 'Frank', 54))
    client_repo.add(Client('6666666666', 'Mando', 21))
    client_repo.add(Client('7777777777', 'Dominic', 41))
    client_repo.add(Client('8888888888', 'Duck', 67))
    client_repo.add(Client('9999999999', 'Mac', 25))
    client_repo.add(Client('1000000000', 'Franklin', 29))

def test_client_repo():
    client_repo = ClientRepoWithDict()
    test_client_repo_init(client_repo)
    first_lenght = 10
    client_repo.add(Client('2000000000', 'Gaby', 30))
    assert len(client_repo.get_all()) == first_lenght+1
    try:
        client_repo.add(Client('2222222222', 'Bob', 29))
        assert False
    except ValueError:
        assert True
    client_repo.remove('3333333333')
    assert len(client_repo.get_all()) == first_lenght
    try:
        client_repo.remove('3748395763')
        assert False
    except ValueError:
        assert True

if __name__ == '__main__':
    test_client_repo()
