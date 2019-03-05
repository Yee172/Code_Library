# n^2 + a n + b, where |a| < 1000, |b| \leq 1000
# Find the product of the coefficients, a and b,
# for the quadratic expression that produces the
# maximum number of primes for consecutive values of n,
# starting with n = 0.
# ----------------------------------------------------
# Analysis: brute force
#           If b is even, then when n is even, the
#           expression is even, which is not prime
#           except 2. Ergo, b must be odd.
#           If a is even, then when n is odd, the
#           expression is even, which is not prime
#           except 2. Ergo, a must be odd.

from lib.prime_sieve import prime_sieve

prime = prime_sieve(10 ** 7)

def find(x):
    lft = 0
    rgt = len(prime) - 1
    while lft < rgt:
        mid = lft + rgt >> 1
        if prime[mid] == x:
            return True
        if prime[mid] < x:
            lft = mid + 1
        else:
            rgt = mid
    return False

def check(a, b):
    f = lambda n: n ** 2 + a * n + b
    cnt = 0
    while find(f(cnt)):
        cnt += 1
    return cnt

maximum = 0
res = []
for a in range(-999, 1000, 2):
    for b in range(-999, 1000, 2):
        count = check(a, b)
        if count == maximum:
            res.append(a * b)
        elif count > maximum:
            res = [a * b]
            maximum = count

print(maximum)
print(res)
