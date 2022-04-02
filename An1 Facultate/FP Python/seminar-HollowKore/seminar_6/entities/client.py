class Client:
    def __init__(self, client_id = '', name = '', age = None):
        self._client_id = client_id
        self._name = name
        self._age = age

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
    def age(self):
        return self._age

    @age.setter
    def age(self, value):
        self._age = value




def test_client():
    c = Client('12345', 'Dan Marco', 25)
    assert c.name == 'Dan Marco' and c.client_id == '12345' and c.age == 25
    c.age = 20
    c.name = 'Olga'
    assert c.age == 20 and c.name == 'Olga'

if __name__ == '__main__':
    test_client()