n, m = map(int, input().split())
a = [input().replace('.', '0') for i in range(n)]
for i in range(n):
    for j in range(m):
        if a[i][j] != '*' and int(a[i][j]) != sum(map(lambda b: b[max(0, j - 1) : j + 2].count('*'), a[max(0, i - 1) : i + 2])):
            print('NO')
            exit()
print('YES')
