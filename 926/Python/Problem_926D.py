a, b, x, y, m = [list(input()) for i in range(6)], [3, 3, 0, 4, 4, 0, 3, 3], 0, 0, 0
for i in range(6):
    for j in range(8):
        c = b[j] - i // 2
        if a[i][j] == '.' and c > m:
            x, y, m = i, j, c
a[x][y] = 'P'
print('\n'.join(''.join(x) for x in a))
