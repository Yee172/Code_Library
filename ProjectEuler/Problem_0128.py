# A hexagonal tile with number 1 is surrounded by a ring
# of six hexagonal tiles, starting at "12 o'clock" and
# numbering the tiles 2 to 7 in an anti-clockwise direction.
# New rings are added in the same fashion, with the next
# rings being numbered 8 to 19, 20 to 37, 38 to 61, and so on.
# The diagram below shows the first two rings.
#        8
#     9    19
# 10     2    18
#     3     7
# 11     1    17
#     4     6
# 12     5    16
#    13    15
#       14
# By finding the difference between tile n and each of
# its six neighbours we shall define PD(n) to be
# the number of those differences which are prime.
# It can be shown that the maximum value of PD(n) is 3.
# If all of the tiles for which PD(n) = 3 are listed in
# ascending order to form a sequence, the 10th tile would be 271.
# Find the 2000th tile in this sequence.
# ----------------------------------------------------
# Analysis: brute force
#           Notice that the tile not at the place of the lower bound or upper bound of a ring would be impossible to achieve PD(n) = 3.
#           If the tile is not at the place of the lower bound or upper bound of a ring,
#              if the tile is not at the corner, then there would be two 1s and the difference at inner ring and outer ring would both be 1, then we get PD(n) \leq 2.
#              if the tile is at the corner, then there would be two 1s,
#                 when the tile is in first ring, we can enumerate it, which shows that PD(n) \leq 2,
#                 when the tile is out of first ring, we can see
#                    its neighbour at inner ring and the neighbour at outer ring in one line share the same parity
#                    and the other two neighbour at outer ring share the same parity,
#                 which implies that PD(n) \leq 2.
#           Then we can just enumerate the lower bound and upper bound to get the result.

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 6
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

def layer_to_upper_bound(n):
    return 3 * (n + 1) * n + 1

def layer_to_lower_bound(n):
    return 1 if n == 0 else 3 * n * (n - 1) + 2

def number_to_layer(x):
    return int((3 + (12 * x - 12) ** .5) / 6)

def same_layer_neighborhood(x, n):
    lower_bound = layer_to_lower_bound(n)
    upper_bound = layer_to_upper_bound(n)
    yield upper_bound if x - 1 < lower_bound else x - 1
    yield lower_bound if x + 1 > upper_bound else x + 1

def get_neighborhood(x):
    n = number_to_layer(x)
    lower_bound = layer_to_lower_bound(n)
    upper_bound = layer_to_upper_bound(n)
    d = (x - lower_bound) // n
    lower_d = 1 if n == 1 else 6 * (n - 1)
    upper_d = 6 * n
    for r in same_layer_neighborhood(x, n):
        yield r
    if not (x - lower_bound) % n:
        yield x - d - lower_d
        p = x + d + upper_d
        yield p
        for r in same_layer_neighborhood(p, n + 1):
            yield r
    else:
        yield x - d - lower_d if x - d - lower_d < lower_bound else lower_bound - lower_d
        yield x - d - lower_d - 1
        yield x + d + upper_d
        yield x + d + upper_d + 1

def PD(x):
    if x == 1:
        return 3
    count = 0
    for y in get_neighborhood(x):
        if is_prime(abs(y - x)):
            count += 1
    return count

count, i = 0, 0
while True:
    x = layer_to_upper_bound(i)
    if PD(x) == 3:
        count += 1
        if count == 2000:
            print(x)
            break
    if PD(x + 1) == 3:
        count += 1
        if count == 2000:
            print(x + 1)
            break
    i += 1
