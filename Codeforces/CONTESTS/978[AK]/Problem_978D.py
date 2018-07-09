n = int(input())
a = list(map(int, input().split()))
if n < 3:
    print(0)
    exit()
r = []
for x in [-1, 0, 1]:
    for y in [-1, 0, 1]:
        f = 1
        t = 0
        s = a[0] + x
        d = a[1] + y - s
        b = range(s, s + n * d, d) if d else [s] * n
        for i in range(n):
            p = abs(b[i] - a[i])
            if p > 1:
                f = 0
                break
            if p == 1:
                t += 1
        if f:
            r.append(t)
print(min(r) if r else -1)
