# A number consisting entirely of ones is called a repunit.
# We shall define R(k) to be a repunit of length k.
# Given that n is a positive integer and GCD(n, 10) = 1,
# it can be shown that there always exists a value, k,
# for which R(k) is divisible by n, and let A(n) be the
# least such value of k.
# Find the least value of n for which A(n) first exceeds one-million.
# ----------------------------------------------------
# Analysis: brute force
#           Hint: according to the pigeonhole principle,
#                 we know that A(n) < n

target = 10 ** 6
i = target - 2 | 1
while True:
    i += 2
    if not i % 5:
        continue
    p = 1
    r = 1
    while p:
        p = (p * 10 + 1) % i
        r += 1
    if r > target:
        break

print(i)
