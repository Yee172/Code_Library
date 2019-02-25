# How many elements would be contained in the set of
# reduced proper fractions for d \leq 1000000?
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers and their phi...')
MAXN = 10 ** 6 + 1
prime = []
vis = [False] * MAXN
phi = [0] * MAXN
vis[0] = True
vis[1] = True
for i in range(2, MAXN):
    if not vis[i]:
        prime.append(i)
        phi[i] = i - 1
    for x in prime:
        if i * x >= MAXN:
            break
        vis[i * x] = True
        if i % x:
            phi[i * x] = phi[i] * (x - 1)
        else:
            phi[i * x] = phi[i] * x
            break
print('Prime number and phi generated successfully.')

print(sum(phi))
