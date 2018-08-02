l, r, n = map(int, [1] + input().split())
def f(x):
    x = int(input(str(x) + '\n'))
    if x:
        return x
    exit()
a = [f(1) for i in range(n)]
for i in range(60):
    m = l + r >> 1
    x = f(m)
    if x * a[i % n] > 0:
        l = m + 1
    else:
        r = m - 1
