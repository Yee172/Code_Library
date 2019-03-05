# Let P(k) be the largest prime that divides any two
# successive terms of the sequence n^{2} + k^{2}.
# Find the last 18 digits of \sum_{k = 1}^{10000000} P(k)
# ----------------------------------------------------
# Analysis: brute force
#           p | n^{2} + k^{2}
#           p | (n + 1)^{2} + k^{2}
#              => p | 2 n + 1
#              => p | (2 n + 1)^{2}
#              => p | 4 n^{2} + 4 n + 1
#           p | n^{2} + k^{2}
#              => p | 4 n^{2} + 4 k^{2}
#              => p | 4 n + 1 - 4 k^{2}
#           p | 2 n + 1
#              => p | 4 n + 2
#              => p | 1 + 4 k^{2}
#           We only have to find the sum of the largest prime factor of 1 + 4 k^{2}
#               1 + 4 k^{2} | 1 + 4 (k + m)^{2}
#           <=> 1 + 4 k^{2} | 1 + 4 k^{2} + 4 m (m + 2 k)
#           <=> 1 + 4 k^{2} | m (m + 2 k)
#           <=> 1 + 4 k^{2} | m or 1 + 4 k^{2} | m + 2 k (in the case of 1 + 4 k^{2} is a prime number)
#           <=> m = n (1 + 4 k^{2}) or m = n (1 + 4 k^{2}) - 2 k, \forall n \in \N
#              => 1 + 4 k^{2} | 1 + 4 (n (1 + 4 k^{2}) \pm k)^{2}, \forall n \in \N

MAXN = 10 ** 7 + 1

candidates = [k ** 2 << 2 | 1 for k in range(MAXN)]
largest_prime_factor = [0] * MAXN

for k in range(1, MAXN):
    x = candidates[k]
    if x <= 2 * k:
        continue
    for i in range(k, MAXN, x):
        largest_prime_factor[i] = max(largest_prime_factor[i], x)
        while not candidates[i] % x:
            candidates[i] //= x
    for i in range(x - k, MAXN, x):
        largest_prime_factor[i] = max(largest_prime_factor[i], x)
        while not candidates[i] % x:
            candidates[i] //= x

print(sum(largest_prime_factor) % 10 ** 18)
