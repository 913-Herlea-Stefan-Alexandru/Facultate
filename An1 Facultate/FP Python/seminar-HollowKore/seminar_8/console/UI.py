from seminar_8.repositories.customerBase import test_customer_base_init, CustomerBase
from seminar_8.validators.clientValidator import CarRentalException
from seminar_8.repositories.rentalRepo import RentalRepo
from seminar_8.repositories.carRepo import CarRepo

class CarRentalUI:
    def __init__(self, cust_base, car_repo, rental_repo):
        self._customer_base = cust_base
        self._car_repo = car_repo
        self._rental_repo = rental_repo
        test_customer_base_init(self._customer_base)
        self._is_running = True
        self._command_dict = {'remove': self._customer_base.remove, 'search': self.__search_ui}

    def __command_split(self, command):
        tokens = command.split(' ', 1)
        com = tokens[0]
        param = tokens[1] if len(tokens) == 2 else ''
        return com, param

    def __search_ui(self, param):
        for client in self._customer_base.search(param):
            print(client.client_id + ' ' + client.name + ' ' , client.age)

    def start(self):
        while self._is_running:
            command = input('command>> ')
            com, param = self.__command_split(command)
            if com in self._command_dict:
                try:
                    self._command_dict[com](param)
                except CarRentalException as ce:
                    print(str(ce))
            elif com == 'exit':
                self._is_running = False
            else:
                print('Invalid command')



if __name__ == '__main__':
    customer_base = CustomerBase()
    car_repo = CarRepo()
    rental_repo = RentalRepo()
    ui = CarRentalUI(customer_base, car_repo, rental_repo)
    ui.start()
