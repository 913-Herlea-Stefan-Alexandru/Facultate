from seminar.seminar_09_913.repository.FileRepo import FileRepo
from seminar.seminar_09_913.domain.Client import Client

class ClientTextFileRepo(FileRepo):
    """
    Inheritance -> TextFileRepository is a Repository

    What we want:
        1. TextFileRepository behaves EXACTLY like Repository
            with one exception
        2. Ingredients are saved to/loaded from a text file
    """
    def __init__(self, file_name = 'clients.txt'):
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
        for client in self._objects:
            line = str(client.id) + ';' + str(client.cnp) + ';' + str(client.name)
            f.write(line)
            f.write('\n')
        f.close()

    def _load(self):
        f = open(self._file_name, 'rt')
        lines = f.readlines()
        f.close()

        for line in lines:
            line = line.split(';')
            super().store(Client(int(line[0]), line[1], line[2]))