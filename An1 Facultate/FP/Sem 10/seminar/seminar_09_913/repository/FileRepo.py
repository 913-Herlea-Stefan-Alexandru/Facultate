from seminar.seminar_09_913.repository.Repository import Repository

class FileRepo(Repository):
    def __init__(self, file_name):
        super().__init__()
        self._file_name = file_name