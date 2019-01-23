# Find the multiplication of the listed digits of the
# fractional prat of a constructed irrational decimal.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 6
s = ''

i = 1
while len(s) < MAXN:
    s += str(i)
    i += 1

res = 1
i = 1
while i < MAXN:
    i *= 10
    res *= int(s[i - 1])
print(res)
