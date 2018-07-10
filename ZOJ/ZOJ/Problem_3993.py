T = int(raw_input())
for _____ in range(T):
    n, R, r = map(int, raw_input().split())
    bp = (R - 2 * r) ** 2
    a = [0 for _ in range(n)]
    for i in range(n):
        x, y = map(int, raw_input().split())
        temp = x ** 2 + y ** 2
        if temp > bp:
            a[i] = temp
    t = min(a)
    b = [_ + 1 for _ in range(n) if a[_] == t]
    print(len(b))
    print(' '.join([str(_) for _ in b]))
