"""
Write a program that manages circles. Each circle has an (x,y) center (x,y - integers) and a the radius r \
(r > 0, r is an integer). Functionalities will be available using a menu or commands:

1. Add a circle
    - read (x, y, radius) from the console
    - if the circle can be created, add it to the list

2. Generate 'n' circles.
    - n is a positive integer read from the keyboard.
    - program generates and stores n distinct circles (distinct = at least one of x,y,radius must differ) ,
        each completely enclosed in the square defined by corners (0,0) and (20,20)

3. Delete all circles contained within a circle
    - identify an existing circle (read its data from the console, or use its index etc.)
    - delete all circles that it fully ... encircles?

4. Display all circle data, sorted ascending by distance to the x = y line (secondary diagonal!?)

Requirements:
    - handle input errors using exceptions
    - unit test for 3. delete

Required modules:
    circle.py    (functions that work directly with circles)
    functions.py (implement program functionalities)
    console.py   (user interface)
"""