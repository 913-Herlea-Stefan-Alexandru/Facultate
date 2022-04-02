from seminar_8.entities.car import Car

class CarRepo:
    def __init__(self):
        self._car_list = []

    @property
    def car_list(self):
        return self._car_list

    def add(self, car):
        self._car_list.append(car)

    def delete_car(self, given_id):
        for car in self._car_list:
            if car.car_id == given_id:
                self._car_list.pop(self._car_list.index(car))
                break