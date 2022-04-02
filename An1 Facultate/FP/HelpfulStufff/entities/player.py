class Player:
    def __init__(self, id, name, power):
        self._id = id
        self._name = name
        self._power = power

    @property
    def id(self):
        return self._id

    @property
    def name(self):
        return self._name

    @property
    def power(self):
        return self._power

    def __str__(self):
        return self._id + '  ' + self._name + '  ' + str(self._power)

    def to_txt(self):
        return self._id + ';' + self._name + ';' + str(self._power)

    @classmethod
    def from_txt(cls, txt_list):
        return cls(txt_list[0], txt_list[1], int(txt_list[2][:-1]))