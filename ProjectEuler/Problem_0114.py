# A row measuring seven units in length has red blocks
# with a minimum length of three units placed on it,
# such that any two red blocks (which are allowed to be
# different lengths) are separated by at least one grey square.
# How many ways can a row measuring fifty units in length be filled?
# ----------------------------------------------------
# Analysis: dynamic programming

n = 50

accumulate_ways = [1, 2, 3, 5]
accumulate_ways_with_red_first = [0, 0, 0, 1]

for i in range(4, n + 1):
    accumulate_ways_with_red_first.append(accumulate_ways_with_red_first[-1] + accumulate_ways[i - 4] + 1)
    accumulate_ways.append(accumulate_ways[-1] + accumulate_ways_with_red_first[-1] + 1)

print(accumulate_ways[n] - accumulate_ways[n - 1])
