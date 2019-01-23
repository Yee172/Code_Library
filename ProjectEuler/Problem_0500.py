# Find the smallest number with 2^{500500} divisors.
# Give your answer modulo 500500507.
# ----------------------------------------------------
# Analysis: greedy algorithm

from queue import PriorityQueue

NEED = 500500
MOD = 500500507

print('Sieving prime numbers...')
MAXN = 8005000
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

res = 1
q = PriorityQueue()
q.put((2, 0, 1))
for _ in range(NEED):
    x, y, z = q.get()
    if z == 1:
        q.put((prime[y + 1], y + 1, 1))
    q.put((x * x, y, z << 1))
    res *= x % MOD
    res %= MOD

print(res)
