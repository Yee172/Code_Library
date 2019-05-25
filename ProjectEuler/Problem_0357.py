# Find the sum of all positive integers n not exceeding
# 100000000 such that for every divisor d of n, d + n / d is prime.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers and decide whether they are square free...')

MAXN = 10 ** 8 + 1
prime = []
is_prime = [True] * MAXN
is_square_free = [False] * MAXN
is_square_free[1] = True
is_prime[0] = False
is_prime[1] = False
for i in range(2, MAXN):
    if is_prime[i]:
        prime.append(i)
        is_square_free[i] = True
    for x in prime:
        if i * x >= MAXN:
            break
        is_prime[i * x] = False
        if i % x:
            is_square_free[i * x] = is_square_free[i]
        else:
            is_square_free[i * x] = False
            break

print('Prime numbers and is_square_free generated successfully.')

res = 3
for i in range(4, MAXN, 2):
    if is_square_free[i]:
        for j in range(1, int(i ** .5) + 1):
            if not i % j:
                if not is_prime[j + i // j]:
                    break
        else:
            res += i

print(res)
