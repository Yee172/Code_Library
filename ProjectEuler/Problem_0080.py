# For the first one hundred natural numbers, find the
# total of the digital sums of the first one hundred
# decimal digits for all the irrational square roots.
# ----------------------------------------------------
# Analysis: brute force

from decimal import Decimal, getcontext
getcontext().prec = 102

print(sum(sum(map(int, str(Decimal(i).sqrt())[: 101].replace('.', '0'))) for i in range(1, 100) if int(i ** .5) ** 2 != i))
