a = sorted([input() for i in range(int(input()))], key=len)
print('YES', *a, sep='\n') if all(x in y for x, y in zip(a, a[1:])) else print('NO')
