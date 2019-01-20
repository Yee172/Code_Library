# Find the sum of the only eleven primes that are both
# truncatable from left to right and right to left.
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

def is_truncatable(x):
    s = str(x)
    if vis[int(s)]:
        return False
    for i in range(1, len(s)):
        if vis[int(s[i:])]:
            return False
        if vis[int(s[:-i])]:
            return False
    return True

print(sum(i for i in range(10, 800000) if is_truncatable(i)))
