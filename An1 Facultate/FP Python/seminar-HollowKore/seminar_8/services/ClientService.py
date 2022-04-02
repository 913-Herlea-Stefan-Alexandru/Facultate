from seminar_8.entities.client import Client

class ClientService:
    def __init__(self, client_repo):
        self._client_repo = client_repo


    def create(self, client_id, cnp, name):
        client = Client(client_id, cnp, name)
        self._client_repo.add(client)
        return client