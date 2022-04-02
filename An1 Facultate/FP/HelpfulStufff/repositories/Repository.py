from errors.RepoError import RepoError

class Repository:
    def __init__(self):
        self._list = []

    def __len__(self):
        return len(self._list)

    def add(self, item):
        if item.id in [i.id for i in self._list]:
            raise RepoError('\nItem with given id already in repo\n')
        self._list.append(item)

    def __getitem__(self, given_id):
        item = None
        for thing in self._list:
            if given_id == thing.id:
                item = thing
                break
        if item == None:
            raise RepoError('\nItem with given id not found\n')
        return item

    def remove(self, given_id):
        item = self[given_id]
        self._list.pop(self._list.index(item))

    def get_all(self):
        return self._list.copy()

    def get_all_ids(self):
        return [item.id for item in self._list]

    def modify(self):
        pass