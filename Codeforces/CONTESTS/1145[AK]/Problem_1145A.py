d = n = int(input())
a = [*map(int, input().split())]
r = 1
while d:
    for i in range(0, n, d):
        if sorted(a[i:i + d]) == a[i:i + d]:
            r = max(r, d)
    d >>= 1
print(r)
