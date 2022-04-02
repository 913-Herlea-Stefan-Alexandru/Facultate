from repositories.Repository import Repository
import pickle

class BinaryRepo(Repository):
    def __init__(self, file_name):
        super().__init__()
        self._fn = file_name
        self._load()

    def add(self, item):
        super().add(item)
        self._save()

    def remove(self, given_id):
        super().remove(given_id)
        self._save()

    def modify(self):
        super().modify()
        self._save()

    def _save(self):
        f = open(self._fn, 'wb')
        for item in self._list:
            pickle.dump(item, f)
        f.close()

    def _load(self):
        try:
            f = open(self._fn, 'rb')
        except FileNotFoundError:
            f = open(self._fn, 'wb')
            f.close()
            return
        while True:
            try:
                super().add(pickle.load(f))
            except EOFError:
                break
        f.close()