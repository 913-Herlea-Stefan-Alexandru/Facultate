
class SparseList:
    def __init__(self):
        self._elements_dict = {}

    def __len__(self):
        key_list = list(self._elements_dict.keys())
        i = key_list[-1] + 1
        return i

    def __getitem__(self, index):
        if index not in self._elements_dict:
            return 0
        return self._elements_dict[index]

    def __setitem__(self, key, value):
        if value != None:
            self._elements_dict[key] = value

    def append(self, value):
        key_list = list(self._elements_dict.keys())
        i = key_list[-1] + 1
        self._elements_dict[i] = value

    def __iter__(self):
        self._index = -1
        return self

    def __next__(self):
        if self._index+1 < len(self):
            self._index += 1
            if self._index not in self._elements_dict:
                return 0
            return self._elements_dict[self._index]
        else:
            raise StopIteration


# Initialise the sparse list
data = SparseList()
# Add elements to the sparse list
data[1] = "a"
data[4] = "b"
data[9] = "c"
# Element at index 14 is 'd'
data[14] = "d"
# append adds the element after the last
# initialised index
data.append("z")
# Prints:
# 0 a 0 0 b 0 0 0 0 c 0 0 0 0 d z
for i in range(0, len(data)):
    print(data[i])