
def create_circle(x, y, radius):
    return {'center': {'x': x, 'y': y}, 'radius': radius}

def get_radius(circle):
    return circle['radius']

def get_x(circle):
    return circle['center']['x']

def get_y(circle):
    return circle['center']['y']