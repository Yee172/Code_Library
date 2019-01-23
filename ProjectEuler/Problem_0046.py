# What is the smallest odd composite that cannot be
# written as the sum of a prime and twice a square?
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 20000
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

for p in prime[1:]:
    t = 1
    p += 2
    while p < MAXN:
        vis[p] = False
        t += 1
        p += 4 * t - 2

print(min(x for x in range(3, MAXN, 2) if vis[x]))
