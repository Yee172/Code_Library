# What is the 10001st prime number?
# ----------------------------------------------------
# Analysis: Euler sieve

print('Sieving prime numbers...')
MAXN = 1000100
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

print(prime[10000])
