from src.validators.validator import ValidationError

class Repository:
    def __init__(self):
        '''
        Creates a list for the students on initialisation
        '''
        self._list = []

    def __len__(self):
        return len(self._list)

    def add(self, item):
        '''
        Adds the given item to the student list
        :param item: The given item (Student object)
        :return: -
        Raises ValidationError if an item with the same id is already in the list
        '''
        if item.id in [it.id for it in self._list]:
            raise ValidationError('\nStudent with given id is already in data base\n')
        self._list.append(item)

    def get_by_student(self, given_student_id):
        '''
        Returns the list of found grades for the student with the given id
        :param given_student_id: The given student id (str)
        :return: The list of found grades for the student with the given id or None if no grade was found
        '''
        found_list = []
        for grade in self._list:
            if grade.student_id == given_student_id:
                found_list.append(grade)
        return found_list

    def get_by_discipline(self, given_discipline_id):
        '''
        Returns the list of found grades for the discipline with the given id
        :param given_discipline_id: The given discipline id (str)
        :return: The list of found grades for the discipline with the given id or None if no grade was found
        '''
        found_list = []
        for grade in self._list:
            if grade.discipline_id == given_discipline_id:
                found_list.append(grade)
        return found_list

    def get_by_stud_disc(self, item):
        found_list = []
        discipline_id = item[:5]
        student_id = item[5:]
        for grade in self._list:
            if grade.discipline_id == discipline_id and grade.student_id == student_id:
                found_list.append(grade)
        return found_list

    def __getitem__(self, given_id):
        '''
        Returns the item found with the given id
        :param given_id: The given item id (str)
        :return: The item found with the given id
        Raises ValidationError if no item was found
        '''
        if not (given_id in [item.id for item in self._list]):
            raise ValidationError('\nStudent with given id not found\n')
        for item in self._list:
            if item.id == given_id:
                return item

    def remove(self, item):
        self._list.pop(self._list.index(item))

    def get_id_list(self):
        return [item.id for item in self._list]

    def modify(self, item, new_name):
        item.name = new_name

    def search(self, search_str):
        '''
        Returns a list of all items found containing the given string in their id or name
        :param search_str: The given string (str)
        :return: The found list of items
        Raises ValidationError if no item was found
        '''
        found_list = []
        for item in self._list:
            if search_str.lower() in item.id or search_str.lower() in item.name.lower():
                found_list.append(item)
        if found_list == []:
            raise ValidationError('\nNo student found\n')
        return found_list
