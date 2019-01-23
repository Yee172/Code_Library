# What is the largest prime factor of
# the number 600851475143?
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 500000
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

x = 600851475143
for p in prime:
    while not x % p:
        x /= p
    if x == 1:
        print(p)
        break
