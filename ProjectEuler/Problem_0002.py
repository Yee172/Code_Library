# Find the sum of the even-valued terms
# in the Fibonacci sequence under 4 million.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 4 * 10 ** 6
s = 0
a, b = 1, 1
while a < MAXN:
    a, b = a + b, a
    s += a * (a & 1 ^ 1)
print(s)
