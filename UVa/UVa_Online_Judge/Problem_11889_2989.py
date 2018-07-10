from math import gcd
f = lambda x, y: x * y // gcd(x, y)
t = int(input())
for _ in range(t):
    a, c = map(int, input().split())
    if c % a:
        print('NO SOLUTION')
    else:
        d = c // a
        for i in range(d, 10000000, d):
            if f(i, a) == c:
                c = i
                break
        print(c)
