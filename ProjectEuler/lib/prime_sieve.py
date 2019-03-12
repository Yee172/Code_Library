def prime_sieve(MAXN=10 ** 7, info=True):
    """Return a list of prime up to MAXN
    if bitarray is installed:
        Sieve of Eratosthenes (Learnt from code of epiclolz)
        PS: faster because of the operation of bitarray
    else:
        Sieve of Euler in normal way
    """
    if info:
        print('Sieving prime numbers...')

    try:
        from bitarray import bitarray
        is_prime = bitarray(MAXN + 1 >> 1)
        is_prime.setall(1)
        is_prime[0] = 0
        for i in range(1, int(MAXN ** .5)):
            if is_prime[i]:
                is_prime[2 * i ** 2 + 2 * i::2 * i + 1] = 0
        prime = [2] + [i * 2 + 1 for i in is_prime.search(bitarray([1]))]
    except:
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
    
    if info:
        print('Prime number generated successfully.')

    return prime
