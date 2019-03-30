# A row measuring n units in length has red blocks with
# a minimum length of m units placed on it, such that
# any two red blocks (which are allowed to be different
# lengths) are separated by at least one black square.
# For m = 50, find the least value of n for which the
# fill-count function first exceeds one million.
# ----------------------------------------------------
# Analysis: dynamic programming

def f(m, n):
    accumulate_ways = list(range(1, m + 1)) + [m + 2]
    accumulate_ways_with_red_first = [0] * m + [1]

    for i in range(m + 1, n + 1):
        accumulate_ways_with_red_first.append(accumulate_ways_with_red_first[-1] + accumulate_ways[i - (m + 1)] + 1)
        accumulate_ways.append(accumulate_ways[-1] + accumulate_ways_with_red_first[-1] + 1)

    return accumulate_ways[n] - accumulate_ways[n - 1]

expect = 10 ** 6
m = 50
n = m
while f(m, n) <= expect:
    n += 1

print(n)
