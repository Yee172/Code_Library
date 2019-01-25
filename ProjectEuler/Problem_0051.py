# Find the smallest prime which, by replacing part of
# the number (not necessarily adjacent digits) with the
# same digit, is part of an eight prime value family.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 1000000
prime = []
vis = [False] * MAXN
vis[0] = True
vis[1] = True
for i in range(2, MAXN):
    if not vis[i]:
        prime.append(i)
    for x in prime:
        if i * x >= MAXN:
            break
        vis[i * x] = True
        if not i % x:
            break
print('Prime number generated successfully.')

def get_res():
    for p in prime:
        s = str(p)
        t = set(s)
        for c in t:
            cnt = sum(not vis[int(s.replace(c, i))] for i in '123456789')
            if s[0] != c:
                cnt += not vis[int(s.replace(c, '0'))]
            if cnt == 8:
                print(p)
                return

get_res()
