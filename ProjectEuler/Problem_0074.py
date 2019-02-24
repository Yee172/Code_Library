# 145 = 1! + 4! + 5!
#    => 145 -> 145
# Another example:
#    169 -> 363601 -> 1454 -> 169
# It is not difficult to prove that EVERY starting number
# will eventually get stuck in a loop.
# How many chains, with a starting number below one million,
# contain exactly sixty non-repeating terms?
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

factorial = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
d = defaultdict(int)
d[1] = 1
d[2] = 1
d[145] = 1
d[40585] = 1
d[871] = 2
d[872] = 2
d[45361] = 2
d[45362] = 2
d[169] = 3
d[1454] = 3
d[363601] = 3

def dfs(n):
    if d[n]:
        return d[n]
    x = 0
    while n:
        x += factorial[n % 10]
        n //= 10
    d[n] = 1 + dfs(x)
    return d[n]

print(sum(map(lambda i: dfs(i) == 60, range(1, 10 ** 6))))
