# Find the smallest prime which, by replacing part of
# the number (not necessarily adjacent digits) with the
# same digit, is part of an eight prime value family.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 1000000
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

def get_res():
    for p in prime:
        s = str(p)
        t = set(s)
        for c in t:
            cnt = sum(is_prime(int(s.replace(c, i))) for i in '123456789')
            if s[0] != c:
                cnt += is_prime(int(s.replace(c, '0')))
            if cnt == 8:
                print(p)
                return

get_res()
