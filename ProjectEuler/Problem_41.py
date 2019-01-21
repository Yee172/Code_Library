# We shall say that an n-digit number is pandigital if
# it makes use of all the digits 1 to n exactly once.
# What is the largest n-digit pandigital prime
# that exists?
# ----------------------------------------------------
# Analysis: \sum_{n = 1}^{9} n = 45
#              => 9-digit number is divisible by 3
#           \sum_{n = 1}^{8} n = 36
#              => 8-digit number is divisible by 3
#           \sum_{n = 1}^{6} n = 21
#              => 6-digit number is divisible by 3
#           \sum_{n = 1}^{5} n = 15
#              => 5-digit number is divisible by 3
#           brute force the remaining

from itertools import permutations

print('Sieving prime numbers...')
MAXN = 100000
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

def is_prime(n):
    if n < MAXN:
        return not vis[n]
    for i in range(len(prime)):
        if prime[i] ** 2 > n:
            break
        if not n % prime[i]:
            return False
    return True

res = 0
for k in [4, 7]:
    n = 0
    for i in range(1, k + 1):
        n = n * 10 + i
    s = str(n)
    for i in permutations(s):
        x = int(''.join(i))
        if is_prime(x):
            res = x

print(res)
