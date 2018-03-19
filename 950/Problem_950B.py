read = lambda: list(map(int, input().split()))
read()
a, b, j, x, y, r = read(), read(), 0, 0, 0, 0
for i in a:
    x += i
    while x > y:
        y += b[j]
        j += 1
    if x == y:
        x, y = 0, 0
        r += 1
print(r)
