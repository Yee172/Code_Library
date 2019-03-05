# Find the smallest number with 2^{500500} divisors.
# Give your answer modulo 500500507.
# ----------------------------------------------------
# Analysis: greedy algorithm

from queue import PriorityQueue
from lib.prime_sieve import prime_sieve

NEED = 500500
MOD = 500500507

prime = prime_sieve(8005000)

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
