# A number n is called deficient if the sum of its
# proper divisors is less than n and it is called
# abundant if this sum exceeds n.
# By mathematical analysis, it can be shown that all
# integers greater than 28123 can be written as the
# sum of two abundant numbers.
# Find the sum of all the positive integers which
# cannot be written as the sum of two abundant numbers.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 28123 + 1
prime = prime_sieve(MAXN)

def d(x):
    n = x
    res = 1
    for p in prime:
        if p * p > x:
            break
        if not x % p:
            t = 0
            while not x % p:
                x //= p
                t += 1
            res *= (pow(p, t + 1) - 1) // (p - 1)
    if x > 1:
        res *= x + 1
    return res - n

deficient_number = []
can = [False] * MAXN
for i in range(2, MAXN):
    if d(i) > i:
        deficient_number.append(i)
        for each in deficient_number:
            if each + i < MAXN:
                can[each + i] = True

res = 0
for i in range(MAXN):
    if not can[i]:
        res += i

print(res)
