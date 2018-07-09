from collections import defaultdict
t = int(input())
for _ in range(t):
    a, b = input().split()
    d = defaultdict(int)
    for x in b:
        d[x] += 1
    r = 0
    for x in a:
        if d[x]:
            r += 1
            d[x] -= 1
        else:
            break
    print(r)
