# Build a triangle from all positive integers in the following way:
#     1
#     2  3
#     4  5  6
#     7  8  9 10
#    11 12 13 14 15
#    16 17 18 19 20 21
#    22 23 24 25 26 27 28
#    29 30 31 32 33 34 35 36
#    37 38 39 40 41 42 43 44 45
#    46 47 48 49 50 51 52 53 54 55
#    56 57 58 59 60 61 62 63 64 65 66
# Each positive integer has up to eight neighbours in the triangle.
# A set of three primes is called a prime triplet if one
# of the three primes has the other two as neighbours in
# the triangle.
# Define S(n) as the sum of the primes in row n which
# are elements of any prime triplet.
# Find S(5678027) + S(7208785).
# ----------------------------------------------------
# Analysis: brute force

import numpy as np
from ProjectEuler.lib.prime_sieve import prime_sieve

MAXN = 6 * 10 ** 6
prime = prime_sieve(MAXN)
move = (((-1, -1), (-1, 1), (1, 0)), ((-1, 0), (1, -1), (1, 1)))

def get_first_number(n):
    return n * (n - 1) + 2 >> 1

def S(n):
    base = get_first_number(n)
    lower_bound = get_first_number(n - 2)
    upper_bound = get_first_number(n + 3)
    shifted_is_prime = np.ones(n * 5, dtype=bool)
    for p in prime:
        if p * p >= upper_bound:
            break
        shifted_is_prime[(lower_bound - 1) // p * p + p - lower_bound::p] = False
    a = np.array([shifted_is_prime[:n - 2],
                  shifted_is_prime[n - 2:2 * n - 3],
                  shifted_is_prime[2 * n - 3:3 * n - 3],
                  shifted_is_prime[3 * n - 3:4 * n - 2],
                  shifted_is_prime[4 * n - 2:]])
    is_prime_triplet = np.zeros(n, dtype=bool)
    for i in range(1, 4):
        for j, f in enumerate(a[i]):
            if f:
                valid = 0
                for x, y in move[n + i & 1]:
                    if 0 <= j + y < n - 2 + i + x:
                        valid += a[i + x][j + y]
                    if valid > 1:
                        break
                if valid > 1:
                    for y in range(-1, 2):
                        if 0 <= j + y < n and a[2][j + y]:
                            is_prime_triplet[j + y] = True
    return base * np.sum(is_prime_triplet) + np.sum(np.where(is_prime_triplet))

print(S(5678027) + S(7208785))
