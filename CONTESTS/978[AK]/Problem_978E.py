rd = lambda: map(int, input().split())
n, w = rd()
s, m, M = [0] * 3
for x in rd():
    s += x
    m = min(m, s)
    M = max(M, s)
print(max(w - M + m + 1, 0))
