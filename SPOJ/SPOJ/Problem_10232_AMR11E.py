p = []
for i in range(2, 55):
    for x in p:
        if not i % x:
            break
    else:
        p.append(i)
a = [0]
for j in range(30, 2670):
    cnt = 0
    i = j
    for x in p:
        if x * x > i:
            break
        if not i % x:
            cnt += 1
            while not i % x:
                i //= x
        if cnt > 2:
            break
    if i > 1:
        cnt += 1
    if cnt > 2:
        a.append(j)
rd = lambda: int(input())
t = rd()
for i in range(t):
    print(a[rd()])
