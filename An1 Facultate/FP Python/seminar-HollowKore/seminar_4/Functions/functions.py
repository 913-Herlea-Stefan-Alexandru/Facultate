from seminar_4.Circle.circle import create_circle, get_x, get_y, get_radius
import random

def add_circle(circle_list, x, y, radius):
    circle_list.append(create_circle(x, y, radius))

def is_int(string):
    try:
        int(string)
        return True
    except ValueError:
        return False

def generate_circles(n, circle_list):
    circle_list.clear()
    for i in range(n):
        x = random.randrange(1, 19)
        y = random.randrange(1, 19)
        radius = random.randrange(1, (20-max(x, y)))
        add_circle(circle_list, x, y, radius)

def delete_circle(circle_list, index):
    circle_list.pop(index)

def is_inside(circle1, circle2):
    x1 = get_x(circle1)
    x2 = get_x(circle2)
    y1 = get_y(circle1)
    y2 = get_y(circle2)
    radius1 = get_radius(circle1)
    radius2 = get_radius(circle2)
    if x1 <= x2:
        if y1 < y2:
            if radius1 + x1 >= radius2 + x2 and radius1 + y1 >= radius2 + y2:
                return True
        else:
            if radius1 + x1 >= radius2 + x2 and y1 - radius1 <= y2 - radius2:
                return True
    else:
        if y1 < y2:
            if x1 - radius1 <= x2 - radius2 and radius1 + y1 >= radius2 + y2:
                return True
        else:
            if x1 - radius1 <= x2 - radius2 and y1 - radius1 <= y2 - radius2:
                return True
    return False

def delete_circles_inside(circle_list, circle):
    index = 0
    no_circles = True
    while index < len(circle_list):
        if circle_list[index] == circle:
            index += 1
            continue
        if is_inside(circle, circle_list[index]):
            delete_circle(circle_list, index)
            no_circles = False
            index -= 1
        index += 1
    if no_circles:
        raise ValueError("No circles found")

def abs_center(circle):
    return abs(get_x(circle) - get_y(circle))

def sort_list(circle_list):
    circle_list.sort(key = abs_center)

def to_str(circle):
    return 'C = ('+str(get_x(circle))+','+str(get_y(circle))+'); R = '+str(get_radius(circle))

'''
=====================================================================
'''

def test_delete_circles_inside():
    list = []
    add_circle(list, 2, 3, 4)
    add_circle(list, 2, 3, 3)
    add_circle(list, 1, 2, 1)
    add_circle(list, 5, 6, 9)
    circle = create_circle(2, 3, 4)
    delete_circles_inside(list, circle)
    assert len(list) == 2

test_delete_circles_inside()