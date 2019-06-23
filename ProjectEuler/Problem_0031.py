# How many different ways can 200 be made
# using any number of 1, 2, 5, 10, 20, 50, 100, 200.
# ----------------------------------------------------
# Analysis: dfs brute force

available = [1, 2, 5, 10, 20, 50, 100, 200]

def dfs(remain, index):
    if not index:
        return 1
    res = 0
    while True:
        res += dfs(remain, index - 1)
        remain -= available[index]
        if remain < 0:
            break
    return res

print(dfs(200, len(available) - 1))
