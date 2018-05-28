rd = lambda: map(eval, input().split())
m, n, r = rd()
ax, ay, bx, by = rd()
r /= n
print(min(r * i * abs(ax - bx) * 3.1415926535 / m + (abs(ay - i) + abs(by - i)) * r for i in range(n + 1)))
