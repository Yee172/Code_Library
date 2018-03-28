n = int(input())
a = list(map(int, input().split()))
b = set(abs(a[i] - a[i - 1]) for i in range(1, n) if abs(a[i] - a[i - 1]) - 1)
m = 10 ** 9
if len(b) > 1:
    print('NO')
elif b:
    b = b.pop()
    if b and all((a[i] - 1) // b == (a[i - 1] - 1) // b for i in range(1, n) if abs(a[i] - a[i - 1]) == 1):
        print('YES')
        print(m, b)
    else:
        print('NO')
else:
    print('YES')
    print(m, m)
