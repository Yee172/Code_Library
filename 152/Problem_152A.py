read = lambda: map(int, input().split())
n, m = read()
a = []
for _ in range(n):
    a.append([int(__) for __ in input()])
b = [max([a[_][__] for _ in range(n)]) for __ in range(m)]
r = 0
for _ in range(n):
    for __ in range(m):
        if a[_][__] == b[__]:
            r += 1
            break
print(r)
