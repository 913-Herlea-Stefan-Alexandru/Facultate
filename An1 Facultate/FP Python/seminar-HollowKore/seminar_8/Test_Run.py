from seminar_8.repositories.customerBase import CustomerBase
from seminar_8.validators.clientValidator import CarRentalException
from seminar_8.repositories.rentalRepo import RentalRepo
from seminar_8.repositories.carRepo import CarRepo
from seminar_8.services.ClientService import ClientService
from seminar_8.services.carService import CarService
from seminar_8.services.rentalService import RentalService

from datetime import date

def test_example():
    client_repo = CustomerBase()
    client_service = ClientService(client_repo)

    aaron = client_service.create(100, "1820203556699", "Aaron")
    bob = client_service.create(101, "2750102885566", "Bob")
    carol = client_service.create(102, "1820604536579", "Carol")

    car_repo = CarRepo()
    car_service = CarService(car_repo)

    audi_a3 = car_service.create(200, "CJ 01 AAA", "Audi", "A3")
    audi_a4 = car_service.create(201, "CJ 01 BBB", "Audi", "A4")
    audi_a5 = car_service.create(202, "CJ 01 CCC", "Audi", "A5")
    audi_a6 = car_service.create(203, "CJ 01 DDD", "Audi", "A6")
    audi_a7 = car_service.create(204, "CJ 01 EEE", "Audi", "A7")
    vw_polo = car_service.create(205, "CJ 01 FFF", "VW", "Polo")
    vw_passat = car_service.create(206, "CJ 01 GGG", "VW", "Passat")
    vw_golf = car_service.create(207, "CJ 01 HHH", "VW", "Golf")
    dacia_lodgy = car_service.create(208, "CJ 01 ERT", "Dacia", "Lodgy")
    dacia_duster = car_service.create(209, "CJ 01 YTH", "Dacia", "Duster")

    rent_repo = RentalRepo()
    rent_service = RentalService(rent_repo, car_repo, client_repo)

    rent_service.create_rental(300, aaron, audi_a3, date(2015, 11, 20), date(2015, 11, 22))
    rent_service.create_rental(301, carol, audi_a5, date(2015, 11, 24), date(2015, 11, 25))
    rent_service.create_rental(302, carol, audi_a6, date(2015, 12, 10), date(2015, 12, 12))
    rent_service.create_rental(303, aaron, audi_a4, date(2015, 11, 21), date(2015, 11, 25))
    rent_service.create_rental(304, aaron, audi_a3, date(2015, 11, 24), date(2015, 11, 27))
    rent_service.create_rental(305, bob, audi_a5, date(2015, 11, 26), date(2015, 11, 27))
    rent_service.create_rental(306, carol, audi_a6, date(2015, 12, 15), date(2015, 12, 20))
    rent_service.create_rental(307, bob, audi_a4, date(2015, 12, 1), date(2015, 12, 10))
    rent_service.create_rental(308, carol, audi_a4, date(2015, 12, 11), date(2015, 12, 15))
    rent_service.create_rental(309, aaron, audi_a5, date(2015, 11, 28), date(2015, 12, 2))

    rent_service.create_rental(310, aaron, vw_polo, date(2015, 11, 20), date(2015, 11, 22))
    rent_service.create_rental(311, carol, vw_golf, date(2015, 11, 24), date(2015, 11, 25))
    rent_service.create_rental(312, carol, vw_passat, date(2015, 12, 10), date(2015, 12, 12))
    rent_service.create_rental(313, aaron, dacia_lodgy, date(2015, 11, 21), date(2015, 11, 25))
    rent_service.create_rental(314, aaron, vw_polo, date(2015, 11, 24), date(2015, 11, 27))
    rent_service.create_rental(315, bob, vw_golf, date(2015, 11, 26), date(2015, 11, 27))
    rent_service.create_rental(316, carol, vw_golf, date(2015, 12, 15), date(2015, 12, 20))
    rent_service.create_rental(317, bob, dacia_duster, date(2015, 12, 1), date(2015, 12, 10))
    rent_service.create_rental(318, carol, dacia_duster, date(2015, 12, 11), date(2015, 12, 15))
    rent_service.create_rental(319, aaron, vw_passat, date(2015, 11, 28), date(2015, 12, 2))

    """
        Statistic 1:
            - "Most rented cars". The list of cars, sorted by the number of times they were rented
        """
    print("Most rented cars. The list of cars, sorted by the number of times they were rented")
    print("Car".ljust(10) + "Times".ljust(40))
    for cr in rent_service.most_often_rented_cars():
        print(cr)

    print("-" * 70)

    """
       Statistic 2:
           - "Most rented cars". The list of cars, sorted by the number of days they were rented
       """
    print("Most rented cars. The list of cars, sorted by the number of days they were rented")
    print("Car".ljust(10) + " Days".ljust(40))
    for cr in rent_service.most_rented_cars():
        print(cr)

    print("-" * 70)

    """
        Statistic 3:
            - "Most rented car make". The list of car makes, sorted by the number of rentals
        """
    print("Most rented car make. The list of car makes, sorted by the number of rentals")
    print("Car make".ljust(15) + "Times".ljust(10))
    for cr in rent_service.most_often_rented_car_make():
        print(cr)

if __name__ == '__main__':
    test_example()
