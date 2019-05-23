# The number 7 is special, because 7 is 111 written in
# base 2, and 11 written in base 6. The number 7 is
# special, because 7 is 111 written in base 2, and 11
# written in base 6.
# We shall call a positive integer with this property
# a strong repunit.
# Find the sum of all strong repunits below 10^{12}.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 12
r = set([1])
for b in range(2, int(MAXN ** .5) + 1):
    n = b * (b + 1) + 1
    while n < MAXN:
        r.add(n)
        n = n * b + 1

print(sum(r))
