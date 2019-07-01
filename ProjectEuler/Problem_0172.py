# How many 18-digit numbers n (without leading zeros) are
# there such that no digit occurs more than three times in n?
# ----------------------------------------------------
# Analysis: brute force

from lib.decorator_lib import memorize

target = 18
repeat_upper_limit = 3

@memorize
def binomial(n, k):
    r = 1
    for i in range(1, k + 1):
        r *= n + 1 - i
        r //= i
    return r

@memorize
def dfs(digit, multiple, remain):
    if digit * repeat_upper_limit < remain:
        return 0
    if not remain:
        return 1
    result = 0
    for i in range(min(repeat_upper_limit, remain) + 1):
        result += dfs(digit - 1, binomial(remain, i), remain - i)
    return result * multiple

print(dfs(10, 1, target) // 10 * 9)
