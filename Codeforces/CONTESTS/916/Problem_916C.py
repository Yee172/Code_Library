#!/usr/bin/env python3
# -*- coding: utf-8 -*-
read = lambda: map(int, input().split())


def generate_first_prime(lower, upper):
    if upper < lower:
        return -1
    if lower is 2:
        return 2
    lower = lower + 1 if lower & 1 is 0 else lower
    for num in range(lower, upper + 1, 2):
        for i in range(2, num):
            if (num % i) is 0:
                break
        else:
            return num
    return -1


def main():
    n, m = read()
    p = generate_first_prime(n, 2 * n - 2)
    print(2, p)
    n1 = 2 * (n - 1) - p
    n2 = p - (n - 1)
    index = 2
    for _ in range(n1):
        print(1, index, 1)
        index += 1
    for _ in range(n2):
        print(1, index, 2)
        index += 1
    remain = m - (n - 1)
    i = 2
    j = 3
    while remain:
        print(i, j, 999)
        j += 1
        if j > n:
            i += 1
            j = i + 1
        remain -= 1
            

main()
