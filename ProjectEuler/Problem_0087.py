# How many numbers below fifty million can be expressed
# as the sum of a prime square, prime cube, and prime
# fourth power?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

prime = prime_sieve(10000)

MAXN = 5 * 10 ** 7
square, cube, quadra = [], [], []
vis = [False] * MAXN
for p in prime:
    x = p ** 2
    if x < MAXN:
        square.append(x)
        x *= p
        if x < MAXN:
            cube.append(x)
            x *= p
            if x < MAXN:
                quadra.append(x)
    else:
        break

for i in square:
    for j in cube:
        p = i + j
        if p < MAXN:
            for k in quadra:
                q = p + k
                if q < MAXN:
                    vis[q] = True
                else:
                    break
        else:
            break
        
print(sum(vis))
