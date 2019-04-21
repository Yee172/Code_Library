# The proper divisors of a number are all the divisors
# excluding the number itself.
# Interestingly the sum of the proper divisors of 220
# is 284 and the sum of the proper divisors of 284 is
# 220, forming a chain of two numbers. For this reason,
# 220 and 284 are called an amicable pair.
# Find the smallest member of the longest amicable chain
# with no element exceeding one million.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
prime = prime_sieve(int(MAXN ** .5))

def d(x):
    n = x
    res = 1
    for p in prime:
        if p * p > x:
            break
        if not x % p:
            t = 0
            while not x % p:
                x //= p
                t += 1
            res *= (pow(p, t + 1) - 1) // (p - 1)
    if x > 1:
        res *= x + 1
    return res - n

smallest_member = 0
longest_chain_length = 0

chain_length = [0] * (MAXN + 1)
proper_divisor_sum = [0] * (MAXN + 1)
for i in range(MAXN + 1):
    proper_divisor_sum[i] = d(i)

def dfs(array):
    x = array[-1]
    if chain_length[x]:
        return 0, 0
    next_x = proper_divisor_sum[x]
    if next_x == 1 or next_x > MAXN:
        return 0, 0
    if next_x in array:
        for i, y in enumerate(array):
            if y == next_x:
                break
        l = len(array) - i
        for y in array[i:]:
            chain_length[y] = l
        return min(array[i:]), l
    return dfs(array + [next_x])

for i in range(MAXN + 1):
    s, l = dfs([i])
    if s:
        if l > longest_chain_length:
            smallest_member = s
            longest_chain_length = l
        elif l == longest_chain_length:
            smallest_member = min(smallest_member, s)

print(smallest_member)
