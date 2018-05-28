rd = lambda: map(int, input().split())
n, k = rd()
b, c = list(rd()), input()
a, d = [[], [], []], {'R': 0, 'W': 1, 'O': 2}
for i in range(n):
    a[d[c[i]]].append(b[i])
for x in a:
    x.sort()
f = lambda x: a[x][-1] + a[2][-1] + sum(sorted(a[x][:-1] + a[2][:-1])[::-1][:k - 2]) if len(a[x]) and len(a[x]) + len(a[2]) >= k else -1
if len(a[2]) and k > 1:
    print(max(f(0), f(1)))
else:
    print(-1)
