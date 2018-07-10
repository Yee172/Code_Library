rd = lambda: map(int, raw_input().split())
t = input()
for _ in xrange(t):
    n, q = rd()
    p = {}
    for x in raw_input().split()[1:]:
        p[x] = 0
    for i in xrange(q):
        s = raw_input().split()[1:]
        for x in s:
            p[x] += 2 ** i
    pp = {}
    for key, value in p.items():
        pp[value] = pp.get(value, []) + [key]
    for i in xrange(n):
        a = rd()
        v = 0
        for i in xrange(q):
            v += a[i] * 2 ** i
        k = pp.get(v, [])
        print(k[0] if len(k) == 1 else "Let's go to the library!!")
