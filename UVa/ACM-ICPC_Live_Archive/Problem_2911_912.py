import sys
for line in sys.stdin:
    m, p, a, b = map(int, line.split())
    x, y, r = 0, 0, a * b
    for i in range(m - 1):
        if r < a:
            x += 1
            r += 1
        else:
            y += 1
            r -= a
    a **= p // 2
    print(int(y * a + (x + r ** p) / a + 0.5))
