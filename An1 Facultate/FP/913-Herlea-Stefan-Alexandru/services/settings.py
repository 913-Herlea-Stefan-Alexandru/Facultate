import configparser

class Settings:
    def __init__(self, file_name = "D:\FP Python\e1-913-Herlea-Stefan-Alexandru\services\settings.properties"):
        self._cp = configparser.SafeConfigParser()
        self._fn = file_name
        self._cp.read(self._fn)
        self._dimensions = int(self._cp['Settings']['DIM'])
        self._apple_count = int(self._cp['Settings']['apple_count'])

    @property
    def dim(self):
        return self._dimensions

    @property
    def apples(self):
        return self._apple_count