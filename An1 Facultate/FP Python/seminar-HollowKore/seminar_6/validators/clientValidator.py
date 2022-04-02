from seminar_6.entities.client import Client

class CarRentalException(Exception):
    def __init__(self, msg):
        self._msg = msg

class ClientValidator:
    def validate(self, client):
        if client.client_id == '' or client.name == '' or client.age == None:
            raise CarRentalException('Invalid client parameters')
        if not isinstance(client.age, int):
            raise CarRentalException('Age must be an integer')




def test_client_validator():
    c = Client('1234', 2)
    val = ClientValidator()
    try:
        val.validate(c)
        assert False
    except CarRentalException:
        assert True

if __name__ == '__main__':
    test_client_validator()