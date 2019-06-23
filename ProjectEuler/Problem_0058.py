# What is the side length of the square spiral for
# which the ratio of primes along both diagonals first
# falls below 10%?
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
is_prime, _ = prime_sieve(MAXN, False, function_is_prime=True)

side_length = 3
right_bottom_number = 9
total_diagonal = 5
prime_diagonal = 3
goal = 0.1
while prime_diagonal / total_diagonal >= goal:
    right_bottom_number += side_length + 1 << 2
    side_length += 2
    total_diagonal += 4
    now = right_bottom_number
    for _ in range(3):
        now -= side_length - 1
        prime_diagonal += is_prime(now)

print(side_length)
