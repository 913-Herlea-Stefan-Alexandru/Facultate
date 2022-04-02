from seminar.seminar_09_913.repository.FileRepo import FileRepo
from seminar.seminar_09_913.domain.Rental import Rental
import datetime

class RentalTextFileRepo(FileRepo):
    """
    Inheritance -> TextFileRepository is a Repository

    What we want:
        1. TextFileRepository behaves EXACTLY like Repository
            with one exception
        2. Ingredients are saved to/loaded from a text file
    """
    def __init__(self, client_repo, car_repo, file_name = 'rentals.txt'):
        super().__init__(file_name)
        self._client_repo = client_repo
        self._car_repo = car_repo
        self._load()

    def store(self, item):
        super().store(item)
        self._save()

    def delete(self, id_):
        super().delete(id_)
        self._save()

    def _save(self):
        f = open(self._file_name, 'wt')
        for rental in self._objects:
            line = str(rental.id) + ';' + str(rental.start) + ';' + str(rental.end) + ';' + str(rental.client.id) + ';'\
                   + str(rental.car.id)
            f.write(line)
            f.write('\n')
        f.close()

    def _load(self):
        f = open(self._file_name, 'rt')
        lines = f.readlines()
        f.close()

        for line in lines:
            line = line.split(';')
            client = self._client_repo.find(int(line[3]))
            car = self._car_repo.find(int(line[4]))
            super().store(Rental(int(line[0]), datetime.datetime.strptime(line[1], '%Y-%m-%d').date(),
                                 datetime.datetime.strptime(line[3], '%Y-%m-%d').date(), client, car))