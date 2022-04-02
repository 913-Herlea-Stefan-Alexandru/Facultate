import math
import random

class Functions:
    def __init__(self, repo):
        self._repo = repo

    def get_sorted_list(self):
        sorted_list = self._repo.get_all()
        sorted_list.sort(reverse=True, key=(lambda a: a.power))
        return sorted_list

    def check_if_qualifications(self):
        player_list = self._repo.get_all()
        length = len(player_list)
        while length % 2 == 0:
            length /= 2
        if length == 1:
            return False
        return True

    def get_opponents_for_qualifications(self):
        player_list = self.get_sorted_list()
        length = len(player_list)
        required = 1
        while required * 2 <= length:
            required *= 2
        required = (length - required)*2
        qualifications_list = []
        for player in player_list[::-1]:
            required -= 1
            qualifications_list.append(player)
            if required == 0:
                break
        return qualifications_list

    def level_up(self, player):
        player.power += 1

    def get_remaining_list(self, losers):
        total_list = self.get_sorted_list()
        i = 0
        while i < len(total_list):
            if total_list[i].id in [player.id for player in losers]:
                total_list.pop(i)
                i -= 1
            i += 1
        return total_list

    def make_groups(self, player_list):
        groups = []
        while len(player_list) != 0:
            i = random.randint(0, len(player_list)-1)
            player1 = player_list.pop(i)
            i = random.randint(0, len(player_list)-1)
            player2 = player_list.pop(i)
            groups.append([player1, player2])
        return groups

    def play_tournament(self, player_list):
        pass