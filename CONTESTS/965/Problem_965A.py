print((lambda k, n, s, p: ((n + s - 1) // s * k + p - 1) // p)(*map(int, input().split())))
