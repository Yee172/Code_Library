# We can easily verify that none of the entries in the
# first seven rows of Pascal's triangle are divisible
# by 7. However, if we check the first one hundred rows,
# we will find that only 2361 of the 5050 entries are
# not divisible by 7.
# Find the number of entries which are not divisible by
# 7 in the first one billion rows of Pascal's triangle.
# ----------------------------------------------------
# Analysis: fractal
#           Similar with Sierpinski triangle, only with
#           log_{2}^{28} Hausdorff-Becikovich Dimesion
#                 1 
#                101                  /\
#               10101           1 -> /__\
#              1010101
#             101010101              ____
#            10101010101        0 -> \  /
#           1010101010101             \/

from math import log

target = 10 ** 9
e = int(log(target) / log(7))

def count_not_divisible(n, exponent):
    if exponent == 0:
        return (1 + n) * n >> 1
    block, remainder = divmod(n, 7 ** exponent)
    return (block + 1) * block // 2 * 28 ** exponent + (block + 1) * count_not_divisible(remainder, exponent - 1)

print(count_not_divisible(target, e))
