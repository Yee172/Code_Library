#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from math import ceil


n, L = [int(_) for _ in input().split(' ')]
res = 0
a = [int(_) for _ in input().split(' ')]
b = [(_ / (2 ** i), i) for i, _ in enumerate(a)]
b.sort(key = lambda x: x[0])


def f(res, L):
    c = len(bin(L)[2:])
    print('c=', c)
    if c >= b[0][1] + 1:
        mul, L = divmod(L, 2 ** b[0][1])
        res += mul * a[b[0][1]]
    else:
        mi = 1e12
        dec = 0
        for _ in range(n):
            m = 2 ** b[_][1]
            d = max(ceil(L / m), 1)
            t = int(a[b[_][1]] * d)
            print(1, b[_][1], m, d, t)
            if t < mi:
                mi = t
                dec = int(m * d)
            if b[_][1] + 1 == c:
                break
        print(2, mi, dec)
        res += mi
        L -= dec
    return res, L


while 1:
    res, L = f(res, L)
    if L <= 0:
        break
print(res)
