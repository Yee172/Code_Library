# Consider numbers t(n) of the form t(n) = 2 n^{2} - 1
# with n > 1.
# How many numbers t(n) are prime for n \leq 50000000?
# ----------------------------------------------------
# Analysis: brute force
#           2 n^{2} - 1 | 2 (n + k)^{2} - 1
#           <=> 2 n^{2} - 1 | 2 n^{2} - 1 + 2 k (k + 2 n)
#           <=> 2 n^{2} - 1 | k (k + 2 n)
#           <=> 2 n^{2} - 1 | k or 2 n^{2} - 1 | k + 2 n (in the case of 2 n^{2} - 1 is a prime number)
#           <=> k = m (2 n^{2} - 1) or k = m (2 n^{2} - 1) - 2 n, \forall m \in \N
#              => 2 n^{2} - 1 | 2 (m (2 n^{2} - 1) \pm n)^{2} - 1

MAXN = 5 * 10 ** 7 + 1

candidates = [2 * n ** 2 - 1 for n in range(MAXN)]
is_prime = [True] * MAXN
is_prime[0] = False
is_prime[1] = False

for n in range(2, MAXN):
    x = candidates[n]
    if x <= 2 * n:
        continue
    for i in range(x + n, MAXN, x):
        is_prime[i] = False
        while not candidates[i] % x:
            candidates[i] //= x
    for i in range(x - n, MAXN, x):
        is_prime[i] = False
        while not candidates[i] % x:
            candidates[i] //= x

print(sum(is_prime))
