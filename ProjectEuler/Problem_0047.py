# Find the first four consecutive integers to have
# four distinct prime factors each. What is the first
# of these numbers?
# ----------------------------------------------------
# Analysis: brute force

from itertools import dropwhile
from lib.prime_sieve import prime_sieve

prime = prime_sieve(10000)

d = dict()

def f(n):
    res = 0
    for p in prime:
        if p * p > n:
            break
        if not n % p:
            res += 1
            while not n % p:
                n //= p
    if n > 1:
        res += 1
    return res

def g(n):
    for i in range(n, n + 4):
        if not d.get(i, 0):
            d[i] = f(i)
        if d[i] != 4:
            return True
    return False

print(dropwhile(g, range(1, 10 ** 8)).__next__())
