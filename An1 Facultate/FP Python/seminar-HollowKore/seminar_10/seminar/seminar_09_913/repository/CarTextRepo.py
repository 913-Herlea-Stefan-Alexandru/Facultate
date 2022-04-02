from seminar.seminar_09_913.repository.FileRepo import FileRepo
from seminar.seminar_09_913.domain.Car import Car

class CarTextFileRepo(FileRepo):
    """
    Inheritance -> TextFileRepository is a Repository

    What we want:
        1. TextFileRepository behaves EXACTLY like Repository
            with one exception
        2. Ingredients are saved to/loaded from a text file
    """
    def __init__(self, file_name = 'cars.txt'):
        super().__init__(file_name)
        self._load()

    def store(self, item):
        super().store(item)
        self._save()

    def delete(self, id_):
        super().delete(id_)
        self._save()

    def _save(self):
        f = open(self._file_name, 'wt')
        for car in self._objects:
            line = str(car.id) + ';' + str(car.license) + ';' + str(car.make) + ';' + str(car.model)
            f.write(line)
            f.write('\n')
        f.close()

    def _load(self):
        f = open(self._file_name, 'rt')
        lines = f.readlines()
        f.close()

        for line in lines:
            line = line.split(';')
            super().store(Car(int(line[0]), line[1], line[2], line[3]))