

def f(n):
    if n < 0:
        raise ValueError()
    if n <= 1:
        return n

    l = [0]*(n+1)
    l[1] = 1
    for i in range(2, n+1):
        l[i] = l[i-1] + l[i-2]
    return l[n]

def test_f():
    n = f(0)
    assert n == 0

    n = f(1)
    assert n == 1

    try:
        n = f(-2)
        assert False
    except ValueError:
        assert True

    n = f(4)
    assert n == 3

    n = f(8)
    assert n == 21

test_f()