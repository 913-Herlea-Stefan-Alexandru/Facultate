class Car:
    def __init__(self, car_id = 0, license_plate = '', make = '', model = ''):
        self._car_id = car_id
        self._license_plate = license_plate
        self._make = make
        self._model = model

    @property
    def car_id(self):
        return self._car_id

    @property
    def license_plate(self):
        return self._license_plate

    @property
    def make(self):
        return self._make

    @property
    def model(self):
        return self._model