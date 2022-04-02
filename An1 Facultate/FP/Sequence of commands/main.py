
def add(param):
    print('Am adaugat ' + param)

def delete(param):
    print('Am sters ' + param)

def split_command(command):
    '''
    Splits the given command string into the command and parameters
    :param command: str: given command string
    :return: str, str: command word and parameters
    '''
    tokens = command.strip().split(' ', 1)
    cmd_word = tokens[0].lower().strip()
    cmd_params = tokens[1].strip() if len(tokens) == 2 else ''
    return cmd_word, cmd_params

def start():
    is_running = True
    command_dict = {'add': add, 'delete': delete}
    while is_running:
        command = input('command>> ')
        commands = command.split(';')
        for comanda in commands:
            command_word, params = split_command(comanda)
            if command_word in command_dict:
                try:
                    command_dict[command_word](params)
                except ValueError as ve:
                    print(str(ve))

start()

