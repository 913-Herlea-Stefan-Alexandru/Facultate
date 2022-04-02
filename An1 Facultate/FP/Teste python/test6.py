a = 1
b = 1
x = int(input('Numarul = '))
c = 1

while c < x:
    c = a + b
    a = b
    b = c

aux = a
a = b - a
b = aux
numar_bazaF = 0

while c > 0:
    if c <= x:
        numar_bazaF = numar_bazaF * 10 + 1
        x -= c
    else:
        numar_bazaF = numar_bazaF * 10
    aux = a
    a = b - a
    c = b
    b = aux

print(numar_bazaF)