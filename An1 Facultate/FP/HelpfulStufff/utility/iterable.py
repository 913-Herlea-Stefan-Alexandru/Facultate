
class Iterable:
    def __init__(self):
        self._list = []

    def __len__(self):
        return len(self._list)

    def index(self, item):
        return self._list.index(item)

    def __getitem__(self, index):
        if index < len(self):
            return self._list[index]

    def __setitem__(self, key, value):
        if value != None:
            self._list[key] = value

    def __add__(self, other):
        self._list.append(other)

    def __delitem__(self, key = None):
        if key == None:
            self._list.pop()
        else:
            self._list.pop(key)

    def __iter__(self):
        self._index = -1
        return self

    def __next__(self):
        if self._index+1 < len(self):
            self._index += 1
            return self._list[self._index]
        else:
            raise StopIteration