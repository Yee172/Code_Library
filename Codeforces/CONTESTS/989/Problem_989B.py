n, p = map(int, input().split())
s = input()
for i in range(p, n):
    x, y = s[i % p], s[i]
    if x == y != '.':
        continue
    if x == y == '.':
        s = (s[:i] + '0' + s[i + 1:]).replace('.', '1')
    elif '1' in [x, y]:
        s = s.replace('.', '0')
    else:
        s = s.replace('.', '1')
    print(s)
    exit()
print('NO')
