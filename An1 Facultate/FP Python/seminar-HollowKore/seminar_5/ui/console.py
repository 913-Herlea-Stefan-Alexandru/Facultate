from seminar_5.services.shelter import shelter


class ShelterUI:
    def __init__(self):
        self._shelter = shelter()

    def start(self):
        """
        ui -> shelter -> entities
        ui -> entities

        Handle main UI loop here
        :return:
        """

        pass

cat_shelter = ShelterUI()
cat_shelter.start()