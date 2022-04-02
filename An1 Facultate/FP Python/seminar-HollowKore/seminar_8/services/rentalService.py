from seminar_8.entities.rental import Rental

class RentalService:
    """
    Class that implements functionalities for Rental entity
    """

    def __init__(self, rental_repo, car_repo, client_repo):
        self._rental_repo = rental_repo
        self._car_repo = car_repo
        self._client_repo = client_repo

    def create_rental(self, rental_id,  client, car, start_date, end_date):
        rental = Rental(client, car, start_date, end_date)
        self._rental_repo.add(client, car, start_date, end_date)

    def filter_rentals(self, client, car):
        """
        Return a list of rentals performed by the provided client for the provided car
        client - The client performing the rental. None means all clients
        cars - The rented car. None means all cars
        """
        result = []
        for rental in self._rental_repo.get_all():
            if client is not None and rental.getClient() != client:
                continue
            if car is not None and rental.car != car:
                continue
            result.append(rental)
        return result

    def most_often_rented_car_make(self):
        """
        The list of car makes, sorted by the number of rental days
        """
        result = []
        # Compute stat using an interim dictionary
        rentals_dict = {}
        for rental in self._rental_repo.get_all():
            if rental.car.make not in rentals_dict:
                rentals_dict[rental.car.make] = 0
            rentals_dict[rental.car.make] += len(rental)
        # Move data to sorted list of values
        for entry in rentals_dict:
            result.append(CarMakeRentalDays(entry, rentals_dict[entry]))
        # Sort the list
        # lambda <parameter list> : <function body>
        result.sort(key=lambda x: x.rental_days, reverse=True)
        return result

    def most_often_rented_cars(self):
        result = []

        rentals_dict = {}
        for rental in self._rental_repo.get_all():
            if rental.car not in rentals_dict:
                rentals_dict[rental.car] = 0
            rentals_dict[rental.car] += 1
        for entry in rentals_dict:
            result.append(CarRentalTimes(entry, rentals_dict[entry]))
        result.sort(key = lambda x: x.rental_times, reverse = True)
        return result

    def most_rented_cars(self):
        result = []

        rentals_dict = {}
        for rental in self._rental_repo.get_all():
            if rental.car not in rentals_dict:
                rentals_dict[rental.car] = 0
            rentals_dict[rental.car] += len(rental)
        for entry in rentals_dict:
            result.append(CarRentalTimes(entry, rentals_dict[entry]))
        result.sort(key = lambda x: x.rental_times, reverse = True)
        return result

class CarRentalTimes:
    def __init__(self, car, car_rental_times):
        self._car = car
        self._car_rental_times = car_rental_times

    @property
    def car(self):
        return self._car

    @property
    def rental_times(self):
        return self._car_rental_times

    def __str__(self):
        return str(self.car.car_id) + ' ' + self.car.make + ' ' + self.car.model + ' - ' + str(self.rental_times)

class CarMakeRentalDays:
    """
    Data Transfer Object for statistics
    SRP: Move data between application layers
    """

    def __init__(self, car_make, car_make_rental_days):
        self._car_make = car_make
        self._car_make_rental_days = car_make_rental_days

    @property
    def make(self):
        return self._car_make

    @property
    def rental_days(self):
        return self._car_make_rental_days

    def __str__(self):
        return self.make + ' - ' + str(self.rental_days)