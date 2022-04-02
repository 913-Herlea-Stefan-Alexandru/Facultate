from datetime import date

from seminar_5.domain.entities import Cat, Stay


class ShelterException(Exception):
    def __init__(self, msg):
        self._msg = msg

class shelter:
    '''
    Shelter functionalities
    '''
    def __init__(self):
        # list of stays for cats in the shelter
        self._stays = []
        # list of cats known in the shelter
        self._cats = []

    def add_cat(self, cat):
        pass

    def add_stay(self, cat, arrival, departure):
        '''
        Add a shelter stay for a given cat
        :param cat: the cat
        :param arrival: date of arrival
        :param departure: date of departur
        :return: -
        Raises shelterException if:
            - arrival date > departure date
        '''
        if arrival > departure:
            raise ShelterException('arrival must take place before departure')
        self._stays.append(Stay(cat, arrival, departure))

    def __len__(self):
        return self.occupancy()

    def occupancy(self):
        '''
        Number of shelter occupations today
        :return:
        '''
        return len(self._stays)

    def find(self):
        pass

    def adopt(self, cat):
        '''
        Adopt a cat from shelter
        :param cat: the cat
        :return: -
        Raises shelterException if cat is not in shelter
        '''
        for stay in self._stays:
            if stay.cat == cat:
                self._stays.remove(stay)
                return
        raise ShelterException('Cat not found')


def test_shelter():
    c1 = Cat(100, 'Tobby', 'domestic short-hair', 3, False)
    c2 = Cat(404, 'Garfield', 'domestic short-hair', 4, False)

    s = shelter()
    assert len(s) == 0
    s.add_stay(c1, date(2020, 10, 28), date(2020, 11, 4))
    assert len(s) == 1

    try:
        s.add_stay(c1, date(2020, 12, 28), date(2020, 11, 4))
        assert False
    except ShelterException:
        assert True
    assert len(s) == 1

    s.adopt(c1)
    assert len(s) == 0

test_shelter()