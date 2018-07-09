ip, rd = lambda: input().split(), lambda: map(int, ip())
n, k, m = rd()
a = ip()
d = dict(zip(a, rd()))
for _ in range(k):
    x = list(rd())[1:]
    m = min(d[a[i - 1]] for i in x)
    for i in x:
        d[a[i - 1]] = m
print(sum(map(lambda x: d[x], ip())))
