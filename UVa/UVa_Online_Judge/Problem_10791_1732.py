from math import gcd
t = 0
def f(n):
    for i in range(int(n ** .5), 0, -1):
        if not n % i:
            j = n // i
            if gcd(j, i) == 1:
                return min(f(i), i) + min(f(j), j) if i - 1 else i + j
while 1:
    t += 1
    n = int(input())
    if n:
        print('Case %d: %d' % (t, f(n)))
    else:
        break
