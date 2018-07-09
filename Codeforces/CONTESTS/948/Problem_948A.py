R, C = map(int, input().split())
r = []
for i in range(R):
    r.append(input().replace('.', 'D'))
    for j in range(C):
        if r[i][j] == 'W' and 'S' in [r[i][max(0, j - 1)],r[i][min(C - 1, j + 1)],r[i - 1][j]] or r[i][j] == 'S' and r[i - 1][j] == 'W':
            print('No')
            exit()
print('Yes')
print('\n'.join(r))
