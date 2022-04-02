class Student:

    def __init__(self, student_id, name):
        self._student_id = student_id
        self._name = name

    @property
    def student_id(self):
        return self._student_id

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    def __str__(self):
        return self._student_id + '     ' + self._name.ljust(20)
