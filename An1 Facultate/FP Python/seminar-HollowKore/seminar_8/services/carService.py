from seminar_8.entities.car import Car

class CarService:
    def __init__(self, car_repo):
        self._car_repo = car_repo

    def create(self, car_id, license_plate, make, model):
        car = Car(car_id, license_plate, make, model)
        self._car_repo.add(car)
        return Car(car_id, license_plate, make, model)