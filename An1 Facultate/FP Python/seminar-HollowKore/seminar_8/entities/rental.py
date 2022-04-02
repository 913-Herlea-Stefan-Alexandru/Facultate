from datetime import date

class Rental:
    def __init__(self, client, car, start, end = None):
        self._client = client
        self._car = car
        self._start = start
        self._end = end

    @property
    def client(self):
        return self._client

    @property
    def car(self):
        return self._car

    @property
    def start(self):
        return self._start

    @property
    def end(self):
        return self._end

    def __len__(self):
        if self._end is not None:
            return (self._end - self._start).days + 1
        today = date.today()
        return (today - self._start).days + 1