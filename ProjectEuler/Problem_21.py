# Let d(n) be defined as the sum of proper divisors of
# n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a \neq b, then a
# and b are an amicable pair and each of a and b
# are called amicable numbers.
# Evaluate the sum of all the amicable numbers
# under 10000.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 10 ** 5
prime = []
vis = [False] * MAXN
vis[0] = True
vis[1] = True
for i in range(2, MAXN):
    if not vis[i]:
        prime.append(i)
    for x in prime:
        if i * x >= MAXN:
            break
        vis[i * x] = True
        if not i % x:
            break
print('Prime number generated successfully.')

MAXN = 10000

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

res = 0
for i in range(2, MAXN):
    j = d(i)
    if not i == j and i == d(j):
        res += i

print(res)
