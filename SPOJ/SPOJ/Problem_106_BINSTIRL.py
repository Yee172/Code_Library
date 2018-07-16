for i in range(int(input())):
    n, m = map(int, input().split())
    w = m - 1 >> 1
    z = n - m + w
    print([0, 1][z & w == w])
