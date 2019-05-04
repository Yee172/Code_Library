# Let N be a positive integer and let N be split into
# k equal parts, r = N / k, so that N = r k.
# Let P be the product of these parts, P = r^{k}.
# Let M(N) = P_{max} for a given value of N.
# Terminating decimal has the form of, for example,
#    M(11) = 14641 / 256 = 57.19140625,
# Let D(N) = N if M(N) is a non-terminating decimal and
# D(N) = -N if M(N) is a terminating decimal.
# Find \sum D(N) for 5 \leq N leq 10000.
# ----------------------------------------------------
# Analysis: brute force

from math import e, gcd, log

MAXN = 10000 + 1
r = 0
for n in range(5, MAXN):
    p = int(n / e)
    q = p if log(n) + p * log(p) < (p + 1) * log(p + 1) else p + 1
    q //= gcd(n, q)
    while not q % 2:
        q //= 2
    while not q % 5:
        q //= 5
    r += n if q != 1 else -n

print(r)
