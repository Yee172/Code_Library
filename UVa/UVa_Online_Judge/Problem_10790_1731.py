case = 1
while 1:
    a, b = map(int, input().split())
    if a and b:
        print('Case %d: %d' % (case, a * (a - 1) * b * (b - 1) >> 2))
        case += 1
    else:
        break
