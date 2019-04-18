# By using each of the digits from the set, {1, 2, 3, 4},
# exactly once, and making use of the four arithmetic
# operations (+, −, *, /) and brackets/parentheses,
# it is possible to form different positive integer targets.
# For example,
#    8 = (4 * (1 + 3)) / 2
#    14 = 4 * (3 + 1 / 2)
#    19 = 4 * (2 + 3) − 1
#    36 = 3 * 4 * (2 + 1)
# Find the set of four distinct digits, a < b < c < d,
# for which the longest set of consecutive positive
# integers, 1 to n, can be obtained, giving your answer
# as a string: abcd.
# ----------------------------------------------------
# Analysis: brute force

from itertools import combinations

def merge(x, y):
    return [x + y, x - y, y - x, x * y] + ([x / y] if y else []) + ([y / x] if x else [])

def get_longest_consecutive(l):
    reachable = dict()
    def dfs(l):
        if len(l) == 1:
            a = l[0]
            if int(a) == a and a > 0:
                a = int(a)
                reachable[a] = 1
            return
        for i, j in combinations(range(len(l)), 2):
            x, y = l[i], l[j]
            remain = l[:i] + l[i + 1:j] + l[j + 1:]
            for value in merge(x, y):
                dfs(remain + [value])

    dfs(l)
    longest_consecutive = 0
    while True:
        if not reachable.get(longest_consecutive + 1, 0):
            break
        longest_consecutive += 1
    return longest_consecutive

print(''.join(map(str, max(([a, b, c, d] for d in range(4, 10) for c in range(3, d) for b in range(2, c) for a in range(1, b)), key=get_longest_consecutive))))
