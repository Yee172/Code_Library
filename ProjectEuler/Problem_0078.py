# Let p(n) represent the number of different ways
# in which n coins can be separated into piles.
# Find the least value of n for which p(n) is divisible
# by one million.
# ----------------------------------------------------
# Analysis: partition number

from itertools import dropwhile
from lib.partition_number import partition_number

MAXN = 6 * 10 ** 4
p = partition_number(MAXN, modulo=10 ** 6)

print(dropwhile(lambda i: p[i], range(1, MAXN)).__next__())
