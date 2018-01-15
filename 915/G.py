#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def isPrime(n):    
    if n <= 1:    
        return False   
    if n == 2:    
        return True   
    if n % 2 == 0:    
        return False   
    i = 3   
    while i * i <= n:    
        if n % i == 0:    
            return False   
        i += 2   
    return True


def generate_prime(n):
    if n >= 2:
        yield 2
    d = 3
    while d <= n:
        if isPrime(d):
            yield d
        d += 2


n, k = [int(_) for _ in input().split(' ')]
r = 0
for i in range(1, k + 1):
    a = i ** n
    for j in generate_prime(i):
        t = i // j
        a -= t ** n
    r += a ^ i
    r %= 1000000007
print(r)
