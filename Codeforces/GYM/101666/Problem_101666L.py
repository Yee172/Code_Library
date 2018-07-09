from decimal import *
from collections import defaultdict
mp = defaultdict(Decimal)
input()
mp['pink'] = Decimal(1)
for l in __import__('sys').stdin.readlines():
    a, b, c = l.split()
    c = Decimal(c)
    mp[a] = max(mp[a], mp[b] * c)
print(min(mp['blue'], 10))
