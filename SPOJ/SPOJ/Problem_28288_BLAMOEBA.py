M = 0x3b9aca07
r = []
input()
for m, n in map(lambda l: map(int, l.split()), __import__('sys').stdin.readlines()):
    y = pow(m, n, M)
    x = (y - 1) * pow(m - 1, M - 2, M) % M
    r.append((x, y))
print('\n'.join(map(lambda a: ' '.join(map(str, a)), r)))
