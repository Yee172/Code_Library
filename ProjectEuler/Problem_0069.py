# Find the value of n \leq 1000000 for which
# n / \varphi(n) is a maximum.
# ----------------------------------------------------
# Analysis: brute force
#           Obviously, it is better for n to have more distinct factors

print('Sieving prime numbers...')
MAXN = 10 ** 3
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

MAXN = 10 ** 6
res = 1
for p in prime:
    if res * p > MAXN:
        break
    res *= p

print(res)
