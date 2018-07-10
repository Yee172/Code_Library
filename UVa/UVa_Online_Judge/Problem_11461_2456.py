f = lambda x: int(x ** .5)
while 1:
    a, b = map(int, input().split())
    if a or b:
        print(f(b) - f(a - 1))
    else:
        break
