# Peter has nine four-sided (pyramidal) dice,
#    each with faces numbered 1, 2, 3, 4.
# Colin has six six-sided (cubic) dice,
#    each with faces numbered 1, 2, 3, 4, 5, 6.
# Peter and Colin roll their dice and compare totals:
#    the highest total wins. The result is a draw if the totals are equal.
# What is the probability that Pyramidal Pete beats Cubic Colin?
# Give your answer rounded to seven decimal places.
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

peter = defaultdict(int)
peter[0] = 1
for i in range(9):
    d = defaultdict(int)
    for x in peter:
        for y in [1, 2, 3, 4]:
            d[x + y] += peter[x]
    peter = d

colin = defaultdict(int)
colin[0] = 1
for i in range(6):
    d = defaultdict(int)
    for x in colin:
        for y in [1, 2, 3, 4, 5, 6]:
            d[x + y] += colin[x]
    colin = d

p = 0
for x in peter:
    for y in colin:
        if x > y:
            p += peter[x] * colin[y]

print(p / (4 ** 9 * 6 ** 6))
