k = int(input())
r = {}
for i in range(k):
    n = int(input())
    a = tuple(map(int, input().split()))
    s = sum(a)
    for j in range(n):
        x = s - a[j]
        if x in r:
            if r[x][0] == i + 1:
                continue
            print('YES')
            print(*r[x])
            print(i + 1, j + 1)
            exit()
        else:
            r[x] = [i + 1, j + 1]
print('NO')
