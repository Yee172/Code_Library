#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
    n = int(input())
    a = [0 for _ in range(n + 1)]
    b = [0 for _ in range(n + 1)]
    c = [0 for _ in range(n + 1)]
    for _ in range(2, n + 1):
        a[_] = int(input())
        b[a[_]] += 1
        c[a[_]] = 1
    for _ in range(2, n + 1):
        if b[_] > 0:
            b[a[_]] -= 1
    for _ in range(1, n + 1):
        if b[_] < 3 and c[_] is 1:
            print('No')
            return
    print('Yes')

main()
