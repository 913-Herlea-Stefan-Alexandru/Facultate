class Client:
    def __init__(self, client_id = 0, cnp = '', name = ''):
        self._client_id = client_id
        self._name = name
        self._cnp = cnp

    @property
    def client_id(self):
        return self._client_id

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def cnp(self):
        return self._cnp

    @cnp.setter
    def cnp(self, value):
        self._cnp = value
