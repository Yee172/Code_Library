# Find the lowest sum for a set of five primes for which
# any two primes concatenate to produce another prime.
# ----------------------------------------------------
# Analysis: brute force

print('Sieving prime numbers...')
MAXN = 10 ** 4
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

def is_prime(n):
    if n < MAXN:
        return not vis[n]
    for p in prime:
        if p ** 2 > n:
            break
        if not n % p:
            return False
    return True

def check(x, y):
    n, x = x, y
    while x:
        n *= 10
        x //= 10
    return is_prime(n + y)

l = len(prime)

print('Creating directed edges from small prime number to big prime number...')
edge = []
for i in range(l):
    x = prime[i]
    add = []
    for j in range(i + 1, l):
        y = prime[j]
        if check(x, y) and check(y, x):
            add.append(j)
    edge.append(add)
print('Edges created successfully.')

def get_res():
    for index0 in range(l):
        for index1 in edge[index0]:
            for index2 in edge[index1]:
                if index2 in edge[index0]:
                    for index3 in edge[index2]:
                        if index3 in edge[index0] and index3 in edge[index1]:
                            for index4 in edge[index3]:
                                if index4 in edge[index0] and index4 in edge[index1] and index4 in edge[index2]:
                                    index_list = (index0, index1, index2, index3, index4)
                                    pair = list(map(lambda i: prime[i], index_list))
                                    print('pair:', pair, 'sum:', sum(pair))

get_res()
