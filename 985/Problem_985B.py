input()
a = tuple(map(lambda s: int(s, 2), __import__('sys').stdin.readlines()))
t = T = 0
for x in a:
    t |= T & x
    T |= x
print(['YES', 'NO'][all(x & (x ^ t) for x in a)])
