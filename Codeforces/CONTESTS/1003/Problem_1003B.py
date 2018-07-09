a, b, x = map(int, input().split())
y = x + 1 >> 1
p = '01'
if a < b:
    p = '10'
    a, b = b, a
print(p[0] * (a - y - 1 + x % 2) + p * y + p[1] * (b - y) + p[0] * (x & 1 ^ 1))
