a = list(map(int, input().split()))
n = 14
f = lambda a: sum(x for x in a if x & 1 ^ 1)
def g(a, x): 
    b = a[:]
    y = a[x]
    b[x] = 0
    for i in range(n):
        b[i] += y // n
    y %= n
    for i in range(x + 1, y + x + 1):
        b[i % 14] += 1
    return f(b)
print(max(g(a, i) for i in range(n)))
