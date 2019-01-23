# What is the smallest positive number that is
# evenly divisible by all of the numbers from 1 to 20?
# ----------------------------------------------------
# Analysis: brute force

from math import gcd

def lcm(x, y):
    return x * y // gcd(x, y)

res = 1
for i in range(1, 21):
    res = lcm(res, i)

print(res)
