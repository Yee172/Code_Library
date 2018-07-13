a, i, m, e = [0], 1, 1, 1
while i <= 10000:
    for _ in range(e):
        a.append(a[-1] + m)
        i += 1
        if i > 10000:
            break
    m *= 2
    e += 1
print('\n'.join(map(lambda i: str(a[int(i)]), __import__('sys').stdin.readlines())))
