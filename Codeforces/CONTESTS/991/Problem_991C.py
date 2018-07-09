def check(n, k):
    r = n + 1 >> 1
    while n > 0:
        p = min(n, k)
        r -= p
        n -= p
        n -= n // 10
    return r <= 0
n = int(input())
l, r = 1, n
while l < r:
    m = l + r >> 1
    if check(n, m):
        r = m
    else:
        l = m + 1
print(l)
