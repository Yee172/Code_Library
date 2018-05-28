n, k = map(int, input().split())
def f(s, i):
    l = max(0, i - k + 1)
    p = max(s.rfind('#', l, i + 1), l - 1)
    r = min(n, i + k)
    q = s.find('#', i, r)
    if q < 0:
        q = r
    return max(0, q - p - k)
a = [[], []]
for _ in range(n):
    a[0].append(input())
a[1] = [''.join(s) for s in zip(*a[0])]
b = []
for i in range(n):
    for j in range(n):
        b.append([f(a[0][i], j) + f(a[1][j], i), i, j])
b.sort()
print(b[-1][1] + 1, b[-1][2] + 1)
