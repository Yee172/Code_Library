n = int(input())
a = []
for _ in range(n):
    h, m = map(int, input().split(':'))
    a.append(h * 60 + m)
    a.append((h + 24) * 60 + m)
a.sort()
b = max(a[i + 1] - a[i] for i in range(2 * n - 1)) - 1
print('%02d:%02d' % divmod(b, 60))
