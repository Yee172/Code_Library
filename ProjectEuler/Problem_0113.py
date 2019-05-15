# Working from left-to-right if no digit is exceeded by
# the digit to its left it is called an increasing number.
# Similarly if no digit is exceeded by the digit to its
# right it is called a decreasing number.
# We shall call a positive integer that is neither
# increasing nor decreasing a "bouncy" number.
# How many numbers below a googol (10^{100}) are not bouncy?
# ----------------------------------------------------
# Analysis: dynamic programming

MAXN = 100
increasing_number = [1] * 10
decreasing_number = [1] * 10
res = 0

for i in range(MAXN):
    for j in range(8, 0, -1):
        increasing_number[j] += increasing_number[j + 1]
    for j in range(1, 10):
        decreasing_number[j] += decreasing_number[j - 1]
    res += increasing_number[1] + decreasing_number[9] - decreasing_number[0] - 9

print(res)
