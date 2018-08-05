from collections import defaultdict
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    d = defaultdict(int)
    for i in range(k):
        a, b, c = map(int, input().split())
        d[b] = max(d[b], c)
    print('Case #%d: %d' %(_ + 1, sum(d.values())))
