# There are n stones in a pond, numbered 1 to n.
# Consecutive stones are spaced one unit apart.
# A frog sits on stone 1. He wishes to visit each stone
# exactly once, stopping on stone n. However, he can only
# jump from one stone to another if they are at most 3
# units apart. In other words, from stone i, he can reach
# a stone j if 1 \leq j \leq n and j is in the set
# {i - 3, i - 2, i - 1, i + 1, i + 2, i + 3}.
# Let f(n) be the number of ways he can do this.
# Let S(L) = \sum_{1}^{L} f(n)^{3}.
# Find S(10^{14}) mod 10^{9}.
# ----------------------------------------------------
# Analysis: Berlekamp-Massey Algorithm

from lib.linear_recursion import LinearRecursion

target = 10 ** 14
modulo = 0x3b9aca00
modulo7 = 0x3b9aca07
modulo9 = 0x3b9aca09
linear_recursion_initial_upper_value = 2001

# using brute force to get
f = LinearRecursion([0, 1, 1, 1, 2, 6, 14, 28])
f.recursion = [2, -1, 2, 1, 1, 0, -1, -1]

F7 = [(f[i] % modulo7) ** 3 % modulo7 for i in range(linear_recursion_initial_upper_value)]
F9 = [(f[i] % modulo9) ** 3 % modulo9 for i in range(linear_recursion_initial_upper_value)]
for i in range(1, linear_recursion_initial_upper_value):
    F7[i] = (F7[i] + F7[i - 1]) % modulo7
    F9[i] = (F9[i] + F9[i - 1]) % modulo9

recursion7 = LinearRecursion(F7, modulo=modulo7).get_recursion()
recursion9 = LinearRecursion(F9, modulo=modulo9).get_recursion()

S = LinearRecursion([(f[i] % modulo) ** 3 % modulo for i in range(len(recursion7))], modulo=modulo)
for i in range(1, len(recursion7)):
    S.initial_values[i] = (S.initial_values[i] + S.initial_values[i - 1]) % modulo

S.recursion = [(recursion7[i] + (recursion7[i] - recursion9[i] >> 1) * modulo7) % modulo for i in range(len(recursion7))]

print(S[target])
