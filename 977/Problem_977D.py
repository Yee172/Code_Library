def f(x, n):
    r = 0
    while not x % n:
        x //= n
        r += 1
    return r
n = int(input())
a = map(int, input().split())
print(*sorted(a, key=lambda x: f(x, 2) - f(x, 3)))
