rd = lambda: map(int, input().split())
n, m = rd()
a = [0] * n
for x in rd():
    a[x - 1] += 1
print(min(a))
