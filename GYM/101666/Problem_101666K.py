__import__('sys').setrecursionlimit(10 ** 6)
n = int(input())
p = []
for i in range(n):
    p.append(tuple(map(lambda c: c == '1', input())))
u = [1] * n
r = []
def dfs(x):
    u[x] = 0
    r.append(x)
    for i in range(n):
        if u[i] & p[x][i]:
            dfs(i)
dfs(0)
print(*r[::-1] if len(r) == n else ['impossible'])
