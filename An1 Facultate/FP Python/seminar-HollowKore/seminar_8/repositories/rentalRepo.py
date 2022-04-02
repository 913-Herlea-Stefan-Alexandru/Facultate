from seminar_8.entities.rental import Rental

class RentalRepo:
    def __init__(self):
        self._rental_list = []

    def add(self, client, car, start_date, end_date):
        self._rental_list.append(Rental(client, car, start_date, end_date))

    def get_all(self):
        return self._rental_list