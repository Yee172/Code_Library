# Sam and Max are asked to transform two digital clocks
# into two "digital root" clocks.
# A digital root clock is a digital clock that calculates
# digital roots step by step.
# When a clock is fed a number, it will show it and then
# it will start the calculation, showing all the intermediate
# values until it gets to the result.
# For example, if the clock is fed the number 137, it
# will show: "137" -> "11" -> "2" and then it will go
# black, waiting for the next number.
# Every digital number consists of some light segments:
# three horizontal (top, middle, bottom) and four vertical
# (top-left, top-right, bottom-left, bottom-right).
# The clocks consume energy only when segments are turned on/off.
# Sam and Max built two different clocks.
# Sam's clock is fed e.g. number 137: the clock shows "137",
# then the panel is turned off, then the next number ("11")
# is turned on, then the panel is turned off again and
# finally the last number ("2") is turned on and, after
# some time, off.
# Max's clock works differently. Instead of turning off
# the whole panel, it is smart enough to turn off only
# those segments that won't be needed for the next number.
# The two clocks are fed all the prime numbers between
# A = 10^{7} and B = 2 \times 10^{7}.
# Find the difference between the total number of transitions
# needed by Sam's clock and that needed by Max's one.
# ----------------------------------------------------
# Analysis: brute force
#            ---0---
#           |       |
#           1       2
#           |       |
#            ---3---
#           |       |
#           4       5
#           |       |
#            ---6---

from bisect import bisect_left
from lib.prime_sieve import prime_sieve

DIGIT_CLOCK = [[1, 1, 1, 0, 1, 1, 1],
               [0, 0, 1, 0, 0, 1, 0],
               [1, 0, 1, 1, 1, 0, 1],
               [1, 0, 1, 1, 0, 1, 1],
               [0, 1, 1, 1, 0, 1, 0],
               [1, 1, 0, 1, 0, 1, 1],
               [1, 1, 0, 1, 1, 1, 1],
               [1, 1, 1, 0, 0, 1, 0],
               [1, 1, 1, 1, 1, 1, 1],
               [1, 1, 1, 1, 0, 1, 1]]

difference = [[0] * 10 for _ in range(10)]
for i in range(10):
    difference[i][i] = sum(DIGIT_CLOCK[i])
    for j in range(i):
        for k in range(7):
            difference[i][j] += DIGIT_CLOCK[i][k] and DIGIT_CLOCK[j][k]
for i in range(10):
    for j in range(i + 1, 10):
        difference[i][j] = difference[j][i]

lower_bound = 10 ** 7
upper_bound = 2 * 10 ** 7 + 1
prime = prime_sieve(upper_bound)
prime = prime[bisect_left(prime, lower_bound):]

def scatter_int(n):
    res = []
    while n:
        res.append(n % 10)
        n //= 10
    return res

res = 0
for x in prime:
    sx = scatter_int(x)
    while x > 9:
        x = sum(sx)
        sy = scatter_int(x)
        for i in range(len(sy)):
            res += difference[sy[i]][sx[i]]
        sx = sy

print(res << 1)
