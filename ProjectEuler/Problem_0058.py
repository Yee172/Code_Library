# What is the side length of the square spiral for
# which the ratio of primes along both diagonals first
# falls below 10%?
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 10 ** 6
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
    for p in prime:
        if p ** 2 > n:
            break
        if not n % p:
            return False
    return True

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
