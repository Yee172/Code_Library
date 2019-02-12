# Find the unique positive integer whose square has
# the form 1_2_3_4_5_6_7_8_9_0, where each "_" is a
# single digit.
# ----------------------------------------------------
# Analysis: brute force
#           notice that last "_" must be 0

for i in reversed(range(10 ** 8, 141421356)):
    x = i ** 2
    mark = 9
    while mark and x % 10 == mark:
        x //= 100
        mark -= 1
    if not mark:
        print(i * 10)
        break
