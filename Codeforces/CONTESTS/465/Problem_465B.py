n = int(input())
a = map(int, input().split())
r = 0
m = 0
for i in range(n):
    p = next(a)
    if p == 1:
        r += 1
        if m:
            r += 1
            m = 0
    else:
        if r:
            m = 1
print(r)
