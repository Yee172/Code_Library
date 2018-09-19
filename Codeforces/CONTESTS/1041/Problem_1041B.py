a, b, x, y = map(int, input().split())
g = __import__('math').gcd(x, y)
x //= g
y //= g
print(min(a // x, b // y))
