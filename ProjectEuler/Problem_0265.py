# 2^{N} binary digits can be placed in a circle so that
# all the N-digit clockwise subsequences are distinct.
# Each circular arrangement can be encoded as a number
# by concatenating the binary digits starting with the
# subsequence of all zeros as the most significant bits
# and proceeding clockwise.
# Calling S(N) the sum of the unique numeric representations,
# we can see that S(3) = 23 + 29 = 52.
# Find S(5).
# ----------------------------------------------------
# Analysis: brute force

n = 5
start = 1 << n + 1 | 1
initial_ones = (1 << n - 1) - 2
initial_zeros = (1 << n - 1) - n
truncation = (1 << n) - 1

res = 0

def check(now):
    now = now << (n - 1) | (1 << n - 2)
    if ('1' * n) not in bin(now):
        return
    visit = [False] * (1 << n)
    s = now >> (1 << n)
    for i in range(truncation, -1, -1):
        s = (s << 1 | bool(1 << i & now)) & truncation
        if visit[s]:
            return
        visit[s] = True
    global res
    res += (now >> n - 2) & (1 << (1 << n)) - 1

def dfs(now, remain_zeros, remain_ones):
    if not remain_zeros and not remain_ones:
        check(now)
        return
    if remain_zeros:
        dfs(now << 1, remain_zeros - 1, remain_ones)
    if remain_ones:
        dfs(now << 1 | 1, remain_zeros, remain_ones - 1)

dfs(start, initial_zeros, initial_ones)

print(res)
