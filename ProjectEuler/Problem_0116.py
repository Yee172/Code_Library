# A row of five grey square tiles is to have a number of its
# tiles replaced with coloured oblong tiles chosen from
# red (length two), green (length three), or blue (length four).
# How many different ways can the grey tiles in a row
# measuring fifty units in length be replaced if colours
# cannot be mixed and at least one coloured tile must be used?
# ----------------------------------------------------
# Analysis: dynamic programming

n = 50

a = [1] * 2
for i in range(2, n + 1):
    a.append(a[-1] + a[-2])

b = [1] * 3
for i in range(3, n + 1):
    b.append(b[-1] + b[-3])

c = [1] * 4
for i in range(4, n + 1):
    c.append(c[-1] + c[-4])

print(a[n] + b[n] + c[n] - 3)
