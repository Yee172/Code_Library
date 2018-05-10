n = int(input())
s = input()
d = {}
for i in range(n - 1):
    x = s[i: i + 2]
    d[x] = d.get(x, 0) + 1
print(max(d, key=d.get))
