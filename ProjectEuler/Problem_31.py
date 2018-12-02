# How many different ways can 200 be made
# using any number of 1, 2, 5, 10, 20, 50, 100, 200.
# ----------------------------------------------------
# Analysis: dfs brute force

available = [1, 2, 5, 10, 20, 50, 100, 200]
cnt = 0

def dfs(remain, index):
    global cnt
    if not index:
        cnt += 1
        return
    while True:
        dfs(remain, index - 1)
        remain -= available[index]
        if remain < 0:
            break

dfs(200, len(available) - 1)
print(cnt)
