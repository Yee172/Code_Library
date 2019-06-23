# Which prime, below one-million, can be written as
# the sum of the most consecutive primes?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 1000000
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

prefix_sum = [0]

for p in prime:
    prefix_sum.append(prefix_sum[-1] + p)

def get_res():
    for i in range(len(prefix_sum) - 1, 0, -1):
        for j in range(0, len(prefix_sum) - i):
            x = prefix_sum[j + i] - prefix_sum[j]
            if x >= MAXN:
                break
            if is_prime(x):
                return print(x, 'contains', i, 'terms')

get_res()
