from math import gcd
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print('Case %d: %s' % (_ + 1, ('Yes', 'No')[c % gcd(a, b) > 0]))
