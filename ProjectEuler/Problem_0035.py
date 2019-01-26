# How many circular primes are there below one million.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 10 ** 6
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

cnt = 0
for x in prime:
    ok = True
    n = str(x)
    if '0' in n:
        continue
    for i in range(1, len(n)):
        ok &= not vis[int(n[i:] + n[:i])]
    cnt += ok

print(cnt)
