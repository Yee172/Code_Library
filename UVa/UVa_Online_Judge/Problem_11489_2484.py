t = int(input())
for _ in range(t):
    a = list(map(lambda c: int(c) % 3, input()))
    b = sum(a) % 3
    print('Case %d:' % (_ + 1), 'S' if b in a and a.count(0) - (b > 0) & 1 else 'T')
