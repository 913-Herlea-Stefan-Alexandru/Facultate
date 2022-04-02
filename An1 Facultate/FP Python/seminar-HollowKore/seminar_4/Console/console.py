from seminar_4.Functions.functions import add_circle, is_int, delete_circles_inside, sort_list, to_str, generate_circles
from seminar_4.Circle.circle import create_circle

def print_menu():
    print('1. Add a circle')
    print('2. Generate \'n\' circles')
    print('3. Delete all circles contained within a circle')
    print('4. Display all circle data, sorted ascending by distance to the x = y line')
    print('x. Exit')

def add_menu_ui(circle_list):
    x = input('Insert x center coordinate of circle: ')
    if is_int(x):
        x = int(x)
    else:
        raise ValueError('\nx should only be integer\n')
    y = input('Insert y center coordinate of circle: ')
    if is_int(y):
        y = int(y)
    else:
        raise ValueError('\nY should only be integer\n')
    radius = input('Insert radius of circle: ')
    if is_int(radius):
        radius = int(radius)
    else:
        raise ValueError('\nRadius should only be integer\n')
    add_circle(circle_list, x, y, radius)

def delete_circles_inside_menu_ui(circle_list):
    x = input('Insert x center coordinate of circle to check: ')
    if is_int(x):
        x = int(x)
    else:
        raise ValueError('X should only be integer')
    y = input('Insert y center coordinate of circle to check: ')
    if is_int(y):
        y = int(y)
    else:
        raise ValueError('Y should only be integer')
    radius = input('Insert radius of circle to check: ')
    if is_int(radius):
        radius = int(radius)
    else:
        raise ValueError('Radius should only be integer')
    circle = create_circle(x, y, radius)
    if not (circle in circle_list):
        raise ValueError('Circle not found')
    delete_circles_inside(circle_list, circle)

def display_list_menu_ui(circle_list):
    copy_list = circle_list.copy()
    sort_list(copy_list)
    for circle in copy_list:
        print(to_str(circle))

def generate_circles_menu_ui(circle_list):
    n = input('How many circles to generate: ')
    if is_int(n):
        n = int(n)
    else:
        raise ValueError('Radius should only be integer')
    generate_circles(n, circle_list)

def start():
    circle_list = []
    command_dict = {'1': add_menu_ui, '2': generate_circles_menu_ui, '3': delete_circles_inside_menu_ui, '4': display_list_menu_ui}
    is_running = True
    while is_running:
        print_menu()
        command = input('\nInsert command: ')
        if command in command_dict:
            try:
                command_dict[command](circle_list)
            except ValueError as ve:
                print(str(ve))
        elif command == 'x':
            is_running = False
        else:
            print('\nInvalid command\n')

start()