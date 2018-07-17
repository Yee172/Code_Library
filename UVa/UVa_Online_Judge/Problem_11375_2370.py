N = 2001
table = [0, 0, 1, 1, 1, 3, 3, 1]
a = [0, 0, 1, 1, 2, 5, 6, 12]
s = [0, 0, 1, 2, 4, 9, 16, 28]
for i in range(8, N):
    a.append(sum(table[j] * a[i - j] for j in range(2, 8)))
    s.append(s[-1] + a[i])
for x in map(int, __import__('sys').stdin.readlines()):
    print(s[x])
