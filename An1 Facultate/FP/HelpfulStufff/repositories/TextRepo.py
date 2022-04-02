from repositories.Repository import Repository

class TextRepo(Repository):
    def __init__(self, file_name, origin):
        super().__init__()
        self._fn = file_name
        self._origin = origin
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
        f = open(self._fn, 'wt')
        for item in self._list:
            line = item.to_txt()
            f.write(line)
            f.write('\n')
        f.close()

    def _load(self):
        try:
            f = open(self._fn, 'rt')
        except FileNotFoundError:
            f = open(self._fn, 'wt')
            f.close()
            return
        lines = f.readlines()
        f.close()

        for line in lines:
            line = line.split(';')
            item = self._origin.from_txt(line)
            super().add(item)
