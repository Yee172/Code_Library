# Find the value of n, 1 < n < 10^{7}, for which \varphi(n)
# is a permutation of n and the ratio n / \varphi(n)
# produces a minimum.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers and their phi...')
MAXN = 10 ** 7
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

print(max(range(2, 10 ** 7), key=lambda n: phi[n] / n if sorted(str(phi[n])) == sorted(str(n)) else 0))
