t = int(input())
f = lambda x: x * (x - 1) // 2
for _ in range(t):
    n = int(input())
    k = n // 2
    print(f(k) + f(n - k))
