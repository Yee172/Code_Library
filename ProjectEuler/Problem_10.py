# Find the sum of all the primes below two million.
# ----------------------------------------------------
# Analysis: Euler sieve

print('Sieving prime numbers...')
MAXN = 2000000
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

print(sum(prime))
