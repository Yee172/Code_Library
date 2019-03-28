# 70 coloured balls are placed in an urn, 10 for each
# of the seven rainbow colours.
# What is the expected number of distinct colours in
# 20 randomly picked balls?
# Give your answer with nine digits after the decimal point.
# ----------------------------------------------------
# Analysis: brute force
#           calculate the condition that balls of each color did not pick,
#           then simplify the formula

from functools import reduce

print(round((1 - reduce(int.__mul__, range(50, 40, -1)) / reduce(int.__mul__, range(70, 60, -1))) * 7, 9))
