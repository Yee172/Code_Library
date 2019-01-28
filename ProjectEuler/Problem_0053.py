# How many, not necessarily distinct, values of
# binom{n}{r}, for 1 \leq n \leq 100, are greater than
# one-million?
# ----------------------------------------------------
# Analysis: brute force

res = 0
MAXN = 10 ** 6
for i in range(1, 101):
    n = 1
    for j in range(1, i + 2 >> 1):
        n *= i - j + 1
        n //= j
        if n > MAXN:
            res += i - 2 * j + 1
            break

print(res)
