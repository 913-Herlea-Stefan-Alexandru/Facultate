"""
domain classes:
    Client
        id (str, unique, driver license)
        name (str)
        age (int)

    ClientValidatorRO
        validate(self, client) function
            no Client field is empty
            age >= 18
            driver license is 10 char str
            raise ValueError if problems

    ClientValidatorUSA
        validate(self, client) function
            no Client field is empty
            age >= 21
            driver license is 2 letters + 6 digits
            raise ValueError if problems

    test_client function

    test_client_validator function

    Car
        license (str, unique)
        make
        model
        color

    CarValidatorRO
        validate(self, car) function
            no Car field is empty
            license is letter_letter_digit_digit_letter_letter_letter
            make one of 'VW' or 'Dacia'
            raise ValueError if problems

    CarValidatorUSA
        validate(self, car) function
            no Car field is empty
            make one of 'Dodge', 'Ford', 'Tesla'
            raise ValueError if problems

    test_car function

    test_car_validator function

    Rental
        car - instance Car
        client - instance of Client
        start_date, end_date - date (Python data type)

    RentalValidator
        validate(self, car) function
            no fields are empty
            start_date in future
            end_date at least 1 day after
            raise ValueError if problems

    test_rental function

    test_rental_validator function

repository classes:
    CarRepositoryWithList [stores the cars in a list]
        add(self, car)
        remove(self, car_id)
        get_all(self) [return all car instances]

    CarRepositoryWithDict [stores the cars in a dict]
        add(self, car)
        remove(self, car_id)
        get_all(self) [return all car instances]

    + test_car_repository
    + test_car_repo_init -> add 10 cars

    ClientRepositoryWithList [stores the cars in a list]
        add(self, client)
        remove(self, client_id)
        get_all(self) [return all client instances]

    ClientRepositoryWithDict [stores the cars in a dict]
        add(self, client)
        remove(self, client_id)
        get_all(self) [return all client instances]

    + test_client_repository
    + test_client_repo_init -> add 10 clients

    RentalRepositoryWithList [stores the cars in a list]
        add(self, rental)
        remove(self, rental_id)
        get_all(self) [return all rental instances]

    RentalRepositoryWithDict [stores the cars in a dict]
        add(self, rental)
        remove(self, rental_id)
        get_all(self) [return all rental instances]

service classes:
    CarService
        __init__(car_repo, car_validator)
        add(self, <list of car attributes>)
            a. create car instance
            b. validate it
            c. add it to car_repo
        remove(self, car_id)
        get_all(self) [return all car instances]

    + test_car_service

    ClientService
        __init__(client_repo, client_validator)
        add(self, <list of client attributes>)
        remove(self, client_id)
        get_all(self) [return all client instances]

    + test_client_service

    RentalService
        __init__(rental_repo, client_repo, car_repo, rental_validator)
        add(self, <list of rental attributes>)
        remove(self, rental_id)
        get_all(self) [return all rental instances]

    + test_rental_service

user interface class:
    MenuUI
        __init__(car_service, client_service, rental_service)
        start()

    CommandUI
        __init__(car_service, client_service, rental_service)
        start()

"""
'''car_repo = CarRepositoryWithList()
car_valid_us = CarValidatorUSA()
car_valid_ro = CarValidatorRO()
car_service = CarService(car_repo, car_valid)

ui = MenuUI(car_service, bla bla)
ui.start()'''