# Find the first four consecutive integers to have
# four distinct prime factors each. What is the first
# of these numbers?
# ----------------------------------------------------
# Analysis: brute force

from itertools import dropwhile

print('Sieving prime numbers...')
MAXN = 10000
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
