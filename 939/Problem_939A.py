input()
a = [1] + list(map(int, input().split()))
print('YES' if any(a[a[x]] == a.index(x) for x in a) else 'NO')
