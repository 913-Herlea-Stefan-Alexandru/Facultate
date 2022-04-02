class Client:
    def __init__(self, id, name, age):
        self.id = id
        self.name = name
        self.age = age

class ClientRepo:
    def __init__(self):
        self._client_list = []

    def add(self, client):
        if client.id in [c.id for c in self._client_list]:
            raise ValueError()
        self._client_list.append(client)

    def __getitem__(self, item):
        for client in self._client_list:
            if client.id == item:
                return client
        return None

class Film:
    def __init__(self, id, nume, gen):
        self.id = id
        self.nume = nume
        self.gen = gen

class FilmRepo:
    def __init__(self):
        self._lista_filme = []

    def add(self, film):
        if film.id in [f.id for f in self._lista_filme]:
            raise ValueError
        self._lista_filme.append(film)

    def __getitem__(self, item):
        for film in self._lista_filme:
            if film.id == item:
                return film
        return None

class Inchiriere:
    def __init__(self, id_client, id_film, durata):
        self.id_client = id_client
        self.id_film = id_film
        self.durata = durata

class InchirieriRepo:
    def __init__(self):
        self._lista_inchirieri = []

    def add(self, inchiriere):
        self._lista_inchirieri.append(inchiriere)

    def get_all(self):
        return self._lista_inchirieri.copy()

class ClientInchirieri:
    def __init__(self, client, nr_inchirieri):
        self.client = client
        self.nr_inchirieri = nr_inchirieri

    def __str__(self):
        return self.client.name + ' - ' + str(self.nr_inchirieri)

class FilmeInchirieri:
    def __init__(self, film, nr_inchirieri):
        self.film = film
        self.nr_inchirieri = nr_inchirieri

    def __str__(self):
        return self.film.nume + ' - ' + str(self.nr_inchirieri)

depozit_c = ClientRepo()
depozit_f = FilmRepo()
depozit_i = InchirieriRepo()

depozit_c.add(Client(5, 'Dan', 65))
depozit_c.add(Client(1, 'Bob', 12))
depozit_c.add(Client(3, 'Roger', 43))
depozit_c.add(Client(7, 'Greg', 22))

depozit_f.add(Film(1, 'Frozen', 'basm'))
depozit_f.add(Film(2, 'Suicide Squad', 'actiune'))
depozit_f.add(Film(3, 'Barbie', 'basm'))
depozit_f.add(Film(4, 'Daddy\'s home', 'comedie'))
depozit_f.add(Film(5, 'Friends', 'serial'))

depozit_i.add(Inchiriere(5, 1, 23))
depozit_i.add(Inchiriere(1, 2, 12))
depozit_i.add(Inchiriere(1, 3, 43))
depozit_i.add(Inchiriere(5, 2, 3))
depozit_i.add(Inchiriere(7, 5, 2))
depozit_i.add(Inchiriere(5, 2, 43))
depozit_i.add(Inchiriere(3, 1, 5))
depozit_i.add(Inchiriere(5, 2, 23))
depozit_i.add(Inchiriere(1, 2, 435))
depozit_i.add(Inchiriere(5, 4, 2))
depozit_i.add(Inchiriere(7, 2, 1))
depozit_i.add(Inchiriere(5, 3, 66))
depozit_i.add(Inchiriere(3, 2, 5))

def clienti_inchirieri_nume(depozit_c, depozit_i):
    dict_clienti = {}
    lista_clienti_inchirieri = []
    for inchiriere in depozit_i.get_all():
        if inchiriere.id_client not in dict_clienti:
            dict_clienti[inchiriere.id_client] = 1
        else:
            dict_clienti[inchiriere.id_client] += 1

    for item in dict_clienti:
        lista_clienti_inchirieri.append(ClientInchirieri(depozit_c[item], dict_clienti[item]))

    lista_clienti_inchirieri.sort(key=(lambda a: a.client.name))
    return lista_clienti_inchirieri

def clienti_inchirieri_inchirieri(depozit_c, depozit_i):
    dict_clienti = {}
    lista_clienti_inchirieri = []
    for inchiriere in depozit_i.get_all():
        if inchiriere.id_client not in dict_clienti:
            dict_clienti[inchiriere.id_client] = 1
        else:
            dict_clienti[inchiriere.id_client] += 1

    for item in dict_clienti:
        lista_clienti_inchirieri.append(ClientInchirieri(depozit_c[item], dict_clienti[item]))

    lista_clienti_inchirieri.sort(reverse=True, key=(lambda a: a.nr_inchirieri))
    return lista_clienti_inchirieri

def filme_inchirieri(depozit_f, depozit_i):
    dict_filme = {}
    lista_filme_inchirieri = []
    for inchiriere in depozit_i.get_all():
        if inchiriere.id_film not in dict_filme:
            dict_filme[inchiriere.id_film] = 1
        else:
            dict_filme[inchiriere.id_film] += 1

    for item in dict_filme:
        lista_filme_inchirieri.append(FilmeInchirieri(depozit_f[item], dict_filme[item]))

    lista_filme_inchirieri.sort(reverse=True, key=(lambda a: a.nr_inchirieri))
    return lista_filme_inchirieri

for item in clienti_inchirieri_nume(depozit_c, depozit_i):
    print(item)
print()
for item in clienti_inchirieri_inchirieri(depozit_c, depozit_i):
    print(item)
print()
for item in filme_inchirieri(depozit_f, depozit_i):
    print(item)