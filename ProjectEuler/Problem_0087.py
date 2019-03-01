# How many numbers below fifty million can be expressed
# as the sum of a prime square, prime cube, and prime
# fourth power?
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 10000
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
