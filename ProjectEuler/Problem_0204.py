# We will call a positive number a generalised Hamming
# number of type n, if it has no prime factor larger
# than n.
# How many generalised Hamming numbers of type 100 are
# there which don't exceed 10^{9}?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

type_number = 100
MAXN = 10 ** 9
prime = prime_sieve(type_number + 1)
prime_length = len(prime)

def dfs(n, index):
    res = 1
    for i in range(index, prime_length):
        m = n * prime[i]
        if m > MAXN:
            break
        res += dfs(m, i)
    return res

print(dfs(1, 0))
