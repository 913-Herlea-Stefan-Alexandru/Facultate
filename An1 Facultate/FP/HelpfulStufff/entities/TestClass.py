class TestClass:
    def __init__(self, id, name, number):
        self._id = id
        self._name = name
        self._number = number

    @property
    def id(self):
        return self._id

    @property
    def name(self):
        return self._name

    @property
    def number(self):
        return self._number

    def __str__(self):
        return self._id + '  ' + self._name + '  ' + str(self._number)

    def to_txt(self):
        return self._id + ';' + self._name + ';' + str(self._number)

    @classmethod
    def from_txt(cls, txt_list):
        return cls(txt_list[0], txt_list[1], int(txt_list[2][:-1]))