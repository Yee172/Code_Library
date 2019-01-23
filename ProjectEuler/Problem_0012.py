# What is the value of the first triangle number
# to have over five hundred divisors?
# ----------------------------------------------------
# Analysis: brute force

num = 500

print('Sieving prime numbers...')
MAXN = 10 ** 6
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

def get_triangle_num(x):
    return x * (x + 1) >> 1

def check(x):
    r = 1
    for p in prime:
        if p * p >= x:
            break
        t = 0
        while not x % p:
            x /= p
            t += 1
        r *= t + 1
    if x > 1:
        r <<= 1
    return r > num

for i in range(MAXN):
    x = get_triangle_num(i)
    if check(x):
        print(x)
        break
