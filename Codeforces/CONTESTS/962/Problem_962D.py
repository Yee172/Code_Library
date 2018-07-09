n = int(input())
d = {}
for i, x in enumerate(map(int, input().split())):
    while x in d:
        del d[x]
        x *= 2
    d[x] = i
print(len(d))
print(*d)
