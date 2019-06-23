# Find the lowest sum for a set of five primes for which
# any two primes concatenate to produce another prime.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 4
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

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
