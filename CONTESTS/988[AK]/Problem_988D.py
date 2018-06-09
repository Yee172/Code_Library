input()
a = frozenset(map(int, input().split()))
m = max(a)
t = []
for x in a:
    d = 1
    while x + d <= m:
        if x + d in a:
            t = [x, x + d]
            if x + 2 * d in a:
                print(3)
                print(x, x + d, x + 2 * d)
                exit()
        d *= 2
if t:
    print(2)
    print(*t)
else:
    print(1)
    print(m)
