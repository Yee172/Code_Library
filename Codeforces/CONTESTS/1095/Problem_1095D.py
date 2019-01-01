n = int(input())
if n == 3:
    print('1 2 3')
    exit()
a = [0] * (n + 1)
for i, l in enumerate(__import__('sys').stdin.readlines()):
    b, c = map(int, l.split())
    a[i + 1] = (b, c)
r = [0] * n
r[0] = 1
for i in range(1, n):
    p, q = a[r[i - 1]]
    r[i] = p if q in a[p] else q
print(*r)
