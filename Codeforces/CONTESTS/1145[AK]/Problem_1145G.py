a = int(''.join(map(lambda s: str(int(not input(s + '\n') == 'ai')), 'RSPP')), 2)
r, p, s = 'R\n', 'P\n', 'S\n'
if a == 3:
    print(p * 10)
if a == 4:
    print(s * 10)
if a == 8:
    print(r * 10)
if not a or a == 5:
    print((s + r + p) * 3 + s)
if a == 6:
    print((r + s + p) * 3 + r)
