# Find the sum of the distinct squarefree numbers in
# the first 51 rows of Pascal's triangle.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 51
prime = prime_sieve(MAXN)

def is_squarefree(n):
    for p in prime:
        if p * p > n:
            break
        if not n % p ** 2:
            return False
        while not n % p:
            n //= p
    return True

Pascal_number = set([1])
row = [1] + [0] * MAXN
for i in range(1, MAXN):
    for j in range(i, 0, -1):
        row[j] += row[j - 1]
        Pascal_number.add(row[j])

print(sum(n for n in Pascal_number if is_squarefree(n)))
