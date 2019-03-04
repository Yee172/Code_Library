# For the first one hundred natural numbers, find the
# total of the digital sums of the first one hundred
# decimal digits for all the irrational square roots.
# ----------------------------------------------------
# Analysis: Pollard’s rho algorithm
#           p | n^{2} + k^{2}
#           p | (n + 1)^{2} + k^{2}
#              => p | 2 n + 1
#              => p | (2 n + 1)^{2}
#              => p | 4 n^{2} + 4 n + 1
#           p | n^{2} + k^{2}
#              => p | 4 n^{2} + 4 k^{2}
#              => p | 4 n + 1 - 4 k^{2}
#           p | 2 n + 1
#              => p | 4 n + 2
#              => p | 1 + 4 k^{2}

print('Sieving prime numbers...')
MAXN = 10 ** 8
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

def largest_prime(n):
    if n < MAXN:
        if not vis[n]:
            return n
    r = 0
    for p in prime:
        if p * p > n:
            break
        if not n % p:
            r = p
            while not n % p:
                n //= p
    if n > 1:
        r = n
    return r

MOD = 10 ** 18
r = 0
for k in range(1, 10 ** 7 + 1):
    if not k % 1000:
        print(k)
    r += largest_prime(k ** 2 << 2 | 1)
    r %= MOD
print(r)
