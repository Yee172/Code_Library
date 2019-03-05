def phi_sieve(MAXN=10 ** 7, only_phi=False, info=True):
    """Return a list of prime and phi up to MAXN
    Sieve of Euler in normal way
    """
    if info:
        print('Sieving prime numbers and their phi...')
    prime = []
    vis = [False] * MAXN
    phi = [0] * MAXN
    vis[0] = True
    vis[1] = True
    for i in range(2, MAXN):
        if not vis[i]:
            prime.append(i)
            phi[i] = i - 1
        for x in prime:
            if i * x >= MAXN:
                break
            vis[i * x] = True
            if i % x:
                phi[i * x] = phi[i] * (x - 1)
            else:
                phi[i * x] = phi[i] * x
                break
    if info:
        print('Prime number and phi generated successfully.')
    if only_phi:
        return phi
    else:
        return prime, phi
