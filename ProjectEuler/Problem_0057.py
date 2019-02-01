# It is possible to show that the square root of two
# can be expressed as an infinite continued fraction.
# \sqrt{2} = 1 + 1 / (2 + 1 / (2 + 1 / (2 + \ldots)))
# By expanding this for the first iteration, we get:
# 1 + 1 / 2 = 3 / 2
# In the first one-thousand expansions, how many
# fractions contain a numerator with more digits than
# denominator?
# ----------------------------------------------------
# Analysis: brute force

res = 0
a, b = 3, 2
for _ in range(2, 1001):
    a, b = a + 2 * b, a + b
    res += len(str(a)) > len(str(b))

print(res)
