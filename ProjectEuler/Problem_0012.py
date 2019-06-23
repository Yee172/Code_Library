# What is the value of the first triangle number
# to have over five hundred divisors?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

num = 500
MAXN = 10 ** 6

prime = prime_sieve(MAXN)

def get_triangle_num(x):
    return x * (x + 1) >> 1

def check(x):
    r = 1
    for p in prime:
        if p * p >= x:
            break
        t = 0
        while not x % p:
            x /= p
            t += 1
        r *= t + 1
    if x > 1:
        r <<= 1
    return r > num

for i in range(MAXN):
    x = get_triangle_num(i)
    if check(x):
        print(x)
        break
