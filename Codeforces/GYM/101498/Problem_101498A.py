from collections import defaultdict
t = int(input())
for _ in range(t):
    n = int(input())
    d = defaultdict(int)
    for i in range(n):
        s, f = input().split()
        d[f] += 1
    r, m = [], 0
    for x in d:
        if d[x] == m:
            r.append(x)
        if d[x] > m:
            m = d[x]
            r = [x]
    print(sorted(r)[0])
