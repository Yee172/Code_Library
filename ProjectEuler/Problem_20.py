# Find the sum of the digits in the number 100!
# ----------------------------------------------------
# Analysis: brute force

from math import factorial
print(sum(map(int, str(factorial(100)))))
