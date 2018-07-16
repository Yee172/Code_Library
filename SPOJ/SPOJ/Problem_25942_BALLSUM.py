from math import gcd
for l in __import__('sys').stdin.readlines():
    n, k = map(int, l.split())
    if n < 0:
        break
    p = (k - 2 + (k & 1)) * (k >> 1)
    q = n * (n - 1)
    g = gcd(p, q)
    if p == 0:
        print(0)
    else:
        print('%d/%d' % (p // g, q // g))
