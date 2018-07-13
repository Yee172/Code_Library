a = [1, 2, 5]
for i in range(3, 1001):
    a.append(a[-1] * 2 + a[-2] + a[-3])
print('\n'.join(map(lambda x: str(a[int(x)]), __import__('sys').stdin.readlines())))
