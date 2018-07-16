from collections import defaultdict
p = []
N = 31623
MOD = 10 ** 9
vis = [0] * N
vis[0] = vis[1] = 1
for i in range(2, N):
    if not vis[i]:
        p.append(i)
    for x in p:
        if i * x >= N:
            break
        vis[i * x] = 1
        if not i % x:
            break
d = (defaultdict(int), defaultdict(int))
for _ in range(2):
    input()
    for n in map(int, input().split()):
        for x in p:
            if x * x > n:
                break
            while not n % x:
                d[_][x] += 1
                n //= x
        if n > 1:
            d[_][n] += 1
r = 1
gao = 0
for x in d[0]:
    t = 1
    e = min(d[0][x], d[1][x])
    while e:
        if e & 1:
            t *= x
            if t >= MOD:
                gao = 1
                t %= MOD
        e >>= 1
        x *= x
        if x >= MOD:
            gao = 1
            x %= MOD
    r *= t
    if r >= MOD:
        gao = 1
        r %= MOD
print([r, '%09d' % r][gao])
