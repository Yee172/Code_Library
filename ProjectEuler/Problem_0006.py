# Find the difference between the sum of the squares
# of the first one hundred natural numbers and
# the square of the sum.
# ----------------------------------------------------
# Analysis: brute force

print(sum(range(1, 101)) ** 2 - sum(map(lambda x: x * x, range(1, 101))))
