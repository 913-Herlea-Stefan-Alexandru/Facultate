"""
Created on Nov 17, 2018

@author: Arthur
"""
from seminar_09_913.domain.Car import CarValidator
from seminar_09_913.domain.Client import ClientValidator
from seminar_09_913.domain.Rental import RentalValidator
from seminar_09_913.repository.Repository import Repository
from seminar_09_913.service.CarService import CarService
from seminar_09_913.service.ClientService import ClientService
from seminar_09_913.service.RentalService import RentalService
from seminar_09_913.service.UndoService import UndoService
from seminar_09_913.util import print_repos_with_message


def undo_example_hard():
    undo_service = UndoService()
    client_repo = Repository()
    car_repo = Repository()

    '''
    Start rental Service
    '''
    rent_repo = Repository()
    rent_validator = RentalValidator()
    rent_service = RentalService(undo_service, rent_validator, rent_repo, car_repo, client_repo)

    '''
    Start client Service
    '''
    client_validator = ClientValidator()
    client_service = ClientService(undo_service, rent_service, client_validator, client_repo)

    '''
    Start car Service
    '''
    car_validator = CarValidator()
    car_service = CarService(undo_service, rent_service, car_validator, car_repo)

    '''
    We add 2 clients
    '''
    sophia = client_service.create(103, "2990511035588", "Sophia")
    carol = client_service.create(104, "2670511035588", "Carol")

    '''
    We add 2 cars
    '''
    hyundai_tucson = car_service.create(201, "CJ 02 TWD", "Hyundai", "Tucson")
    toyota_corolla = car_service.create(202, "CJ 02 FWD", "Toyota", "Corolla")
    print_repos_with_message("Added 2 clients and 2 cars", client_repo, car_repo, None)

    '''
    We delete 1 client and 1 car
    '''
    client_service.delete(103)
    car_service.delete(202)
    print_repos_with_message("Deleted Sophia and the Corolla", client_repo, car_repo, None)

    '''
    We undo twice
    '''
    undo_service.undo()
    print_repos_with_message("1 undo, the Corolla is back", client_repo, car_repo, None)
    undo_service.undo()
    print_repos_with_message("1 undo, Sophia is back", client_repo, car_repo, None)

    '''
    Redo twice 
    '''
    undo_service.redo()
    undo_service.redo()
    print_repos_with_message("2 redos, Sophia and the Corolla are again deleted", client_repo, car_repo, None)

    '''
    Last redo
    '''
    undo_service.redo()
    print_repos_with_message("1 redo - but there are no more redos", client_repo, car_repo, None)


undo_example_hard()
