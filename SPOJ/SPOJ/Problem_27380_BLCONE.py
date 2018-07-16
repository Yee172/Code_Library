for i in range(int(input())):
    R, H = map(int, input().split())
    L = ((R * R + H * H) * 10 ** 14) ** .5
    A = 6 * H * H * L / R * 10 ** 14
    B = 3 * L / R
    l = 0
    r = H * 10 ** 7
    while l < r:
        m = l + r + 1 >> 1
        if m ** 3 + B * m * m - A > 0:
            r = m - 1
        else:
            l = m
    print('%d.%06d' % divmod(round(l / 10), 10 ** 6))
