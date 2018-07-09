R, x, y, s, t = map(int, input().split())
f = lambda x, y: x * x + y * y
g = lambda x: x ** 0.5
d = f(x - s, y - t)
if not d:
    R /= 2
    x += R
elif d < R * R:
    x -= s
    y -= t
    r = g(f(x, y))
    x /= r
    y /= r
    R = (g(d) + R) / 2
    x *= R
    y *= R
    x += s
    y += t
print(x, y, R)
