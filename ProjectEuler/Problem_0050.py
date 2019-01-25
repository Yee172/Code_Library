# Which prime, below one-million, can be written as
# the sum of the most consecutive primes?
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

prefix_sum = [0]

for p in prime:
    prefix_sum.append(prefix_sum[-1] + p)

def get_res():
    for i in range(len(prefix_sum) - 1, 0, -1):
        for j in range(0, len(prefix_sum) - i):
            x = prefix_sum[j + i] - prefix_sum[j]
            if x >= MAXN:
                break
            if not vis[x]:
                return print(x, 'contains', i, 'terms')

get_res()
