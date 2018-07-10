rd = lambda: map(int, raw_input().split())
t = input()
for _ in xrange(t):
    n, m, X, Y = rd()
    r, x, y = 0, [], []
    for _ in xrange(X):
        x.append(list(rd()))
    for _ in xrange(Y):
        y.append(list(rd()))
    i, j = 0, 0
    while i < X and j < Y:
        xl, xr = x[i]
        yl, yr = y[j]
        if xr < yl:
            i += 1
            continue
        if yr < xl:
            j += 1
            continue
        if xl < yl:
            if xr > yr:
                d = yr - yl + 2 - m
                j += 1
            else:
                d = xr - yl + 2 - m
                i += 1
        else:
            if xr > yr:
                d = yr - xl + 2 - m
                j += 1
            else:
                d = xr - xl + 2 - m
                i += 1
        if d > 0:
            r += d
    print(r)
