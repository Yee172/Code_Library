# Find the sum of all the numbers that can be written
# as the sum of fifth powers of their digits.
# ----------------------------------------------------
# Analysis: brute force

print(sum(i for i in range(10, 5 * 9 ** 5) if i == sum(map(lambda x: int(x) ** 5, str(i)))))
