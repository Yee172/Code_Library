# How many different ways can one hundred be written
# as a sum of at least two positive integers?
# ----------------------------------------------------
# Analysis: brute force

from lib.partition_number import partition_number

p = partition_number(101)

print(p[100] - 1)
