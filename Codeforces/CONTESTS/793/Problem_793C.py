rd = lambda: map(int, input().split())
n = int(input())
x1, y1, x2, y2 = rd()
l = []
r = []
m = []
for i in range(n):
    t = []
    rx, ry, vx, vy = rd()
    m.append([rx, ry, vx, vy])
    if x1 <= rx <= x2 and y1 <= ry <= y2:
        t.append(0)
        if vx == 0 and vy == 0:
            t.append(0x3f3f3f3f3f3f3f3f)
    if vx:
        t1 = (x1 - rx) / vx
        if t1 >= 0:
            if y1 <= ry + t1 * vy <= y2:
                t.append(t1)
        t1 = (x2 - rx) / vx
        if t1 >= 0:
            if y1 <= ry + t1 * vy <= y2:
                t.append(t1)
    if vy:
        t1 = (y1 - ry) / vy
        if t1 >= 0:
            if x1 <= rx + t1 * vx <= x2:
                t.append(t1)
        t1 = (y2 - ry) / vy
        if t1 >= 0:
            if x1 <= rx + t1 * vx <= x2:
                t.append(t1)
    if len(t) < 2:
        print(-1)
        exit()
    t.sort()
    l.append(t[0])
    r.append(t[-1])
l.sort()
r.sort()
if l[-1] > r[0]:
    print(-1)
else:
    p = (l[-1] + r[0]) / 2
    if not all(x1 < rx + p * vx < x2 and y1 < ry + p * vy < y2 for rx, ry, vx, vy in m):
        print(-1)
    else:
        print(l[-1])
