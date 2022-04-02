from seminar.seminar_09_913.domain.Client import Client
from seminar.seminar_09_913.service.UndoService import FunctionCall, Operation, CascadeOperations


class ClientService:
    def __init__(self, undo_service, rental_service, validator, repository):
        self._validator = validator
        self._repository = repository
        self._rental_service = rental_service
        self._undo_service = undo_service

    def create(self, client_id, client_cnp, client_name):
        client = Client(client_id, client_cnp, client_name)
        self._validator.validate(client)
        self._repository.store(client)

        undo_func = FunctionCall(self._repository.delete, client_id)
        redo_func = FunctionCall(self._repository.store, client)
        op = Operation(undo_func, redo_func)
        self._undo_service.record(op)

        return client

    def delete(self, client_id):
        """
            1. Delete the client
        """
        client = self._repository.find(client_id)
        self._repository.delete(client_id)

        undo_func = FunctionCall(self._repository.store, client)
        redo_func = FunctionCall(self._repository.delete, client_id)

        op = Operation(undo_func, redo_func)

        '''
            2. Delete their rentals
            NB! This implementation is not transactional, i.e. the two delete operations are performed separately
        '''
        cascade_list = [op]

        rentals = self._rental_service.filter_rentals(client, None)
        for rent in rentals:
            self._rental_service.delete_rental(rent.getId(), False)
            undo_func = FunctionCall(self._rental_service._repository.store, rent)
            redo_func = FunctionCall(self._rental_service._repository.delete, rent.id)
            cascade_list.append(Operation(undo_func, redo_func))

        self._undo_service.record(CascadeOperations(*cascade_list))

        return client

    def get_client_count(self):
        return len(self._repository)

    def update(self, car):
        """
            NB! Undo/redo is also needed here
        """
        pass
