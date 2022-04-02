# Source code for Test 1 program. Success!
'''
Domain
'''

def create_function(name, param, definition):
    param[-1] = param[-1][:-1]
    return [name, param, definition]

def get_name(function):
    return function[0]

def get_param(function):
    return function[1]

def get_definition(function):
    return function[2]


'''
Functions
'''

def add_command(command_list, param):
    '''
    Adds a command to the list of commands
    :param command_list: the list of commands
    :param param: the command to add
    :return: -
    Raises ValueError if the command is already in the list
    '''
    tokens = param.strip().split('(', 1)
    name = tokens[0]
    com = find_command(command_list, name)
    if not (com == None):
        raise ValueError('Command name already in list')
    if len(tokens) == 1 or tokens[1] == '':
        raise ValueError('No parameters given')
    param_def = tokens[1].strip().split('=', 1)
    params = param_def[0].strip().split(',')
    if len(param_def) == 1 or param_def[1] == '':
        raise ValueError('No definition given')
    definition = param_def[1]
    command_list.append(create_function(name, params, definition))

def find_command(command_list, param):
    '''
    Returns the command from the list of commands. If not found returns None
    :param command_list: the list of commands
    :param param: the command to find
    :return: the command if found and None if not found
    '''
    for f in command_list:
        if param == get_name(f):
            return f
    return None

def list_command(command_list, param):
    '''
    Returns a string version of the given command
    :param command_list: the list of commands
    :param param: the command to transform
    :return: the string value of the given function
    Raises ValueError if no command as found in the list
    '''
    com = find_command(command_list, param)
    if com == None:
        raise ValueError('No command found')
    name = get_name(com)
    params = get_param(com)
    definition = get_definition(com)
    return 'def ' + name + '(' + ''.join((p + ',') for p in params) + '\b): return ' + definition

def evaluate_function(command, params):
    '''
    Evaluates the given function adn returns a string with the python code to be executed
    :param command: the given command
    :param params: the given parameters
    :return: the string of code to be ran by python
    Raises ValueError if the number of parameters given is not the same as the number of parameters of the function
    '''
    definition = get_definition(command)
    par = get_param(command)
    params[-1] = params[-1][:-1]
    com_str = ''
    if len(params) != len(par):
        raise ValueError('Wrong parameters')
    i = 0
    while i < len(params):
        com_str += par[i] + ' = ' + params[i] + '\n'
        i += 1
    com_str += 'print(' + definition + ')'
    return com_str


'''
UI
'''

def eval_ui(command_list, param):
    tokens = param.strip().split('(', 1)
    name = tokens[0]
    if tokens[1] == '':
        raise ValueError('No parameters given')
    params = tokens[1].strip().split(',')
    com = find_command(command_list, name)
    if com == None:
        raise ValueError('Command not found')
    exec(evaluate_function(com, params))

def print_command_ui(command_list, param):
    com_string = list_command(command_list, param)
    print(com_string)

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

def start_command_ui():
    '''
    Handles user commands and all of the functionalities of the program
    :return: -
    '''
    is_running = True
    command_dict = {'add': add_command, 'list': print_command_ui, 'eval': eval_ui}
    command_list = []
    while is_running:
        command = input("command>> ")
        command_word, command_params = split_command(command)
        if command_word in command_dict:
            try:
                command_dict[command_word](command_list, command_params)
            except ValueError as ve:
                print(str(ve))
        elif command_word == 'exit':
            is_running = False
        else:
            print("Wrong command")

start_command_ui()