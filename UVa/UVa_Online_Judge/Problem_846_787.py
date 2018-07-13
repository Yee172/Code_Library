input()
r = []
for l in __import__('sys').stdin.readlines():
    x, y = map(int, l.split())
    d = y - x - 1
    r.append(int((max(4 * d + 1, 0)) ** .5))
print('\n'.join(map(str, r)))
