from errors.RepoError import RepoError

class MenuUI:
    def __init__(self, functions):
        self._functions = functions
        self._is_running = True

    def _main_menu(self):
        print('\n1. Print all players')
        print('2. Start tournament')
        print('x. Exit')

    def _print_players(self):
        player_list = self._functions.get_sorted_list()
        for player in player_list:
            print(player)

    def _play_games(self, player_list):
        for player in player_list:
            print(player)
        print('\ntournament started\n')
        while len(player_list) > 1:
            print('last ' + str(len(player_list)))
            groups = self._functions.make_groups(player_list)
            winners = []
            losers = []
            for group in groups:
                print(str(group[0]) + ' vs ' + str(group[1]))
                while True:
                    read_id = input('Enter the winner\'s id: ')
                    if read_id in [player.id for player in group]:
                        break
                    else:
                        print('\ninvalid id\n')
                for player in group:
                    if read_id == player.id:
                        winners.append(player)
                    else:
                        losers.append(player)
            player_list = winners.copy()
        print('Winner ' + str(player_list[0]))
        self._functions.level_up(player_list[0])

    def _start_tournament(self):
        self._print_players()
        player_list = self._functions.get_sorted_list()
        if self._functions.check_if_qualifications():
            print('qualifications will be played first')
            player_list = self._functions.get_opponents_for_qualifications()
            groups = self._functions.make_groups(player_list)
            winners = []
            losers = []
            for group in groups:
                print(str(group[0]) + ' vs ' + str(group[1]))
                while True:
                    read_id = input('Enter the winner\'s id: ')
                    if read_id in [player.id for player in group]:
                        break
                    else:
                        print('\ninvalid id\n')
                for player in group:
                    if read_id == player.id:
                        winners.append(player)
                    else:
                        losers.append(player)
            player_list = self._functions.get_remaining_list(losers)
        self._play_games(player_list)

    def start(self):
        command_dict = {'1': self._print_players, '2': self._start_tournament}
        while self._is_running:
            self._main_menu()
            command = input('Command: ')
            if command in command_dict:
                try:
                    command_dict[command]()
                except RepoError as re:
                    print(str(re))
            elif command.lower() == 'x':
                self._is_running = False
            else:
                print('\nInvalid command\n')