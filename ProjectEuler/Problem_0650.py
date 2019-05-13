# Let B(n) be the product of binomial coefficients.
# Let D(n) be the sum of the divisors of B(n).
# Let S(n) = \sum_{k = 1}^{n} D(n).
# Find S(20000) mod 1000000007.
# ----------------------------------------------------
# Analysis: Legendre's formula
#           Hint: B(n) = (n!)^{n + 1} / (\prod_{i = 0}^{n} i!)^{2}
#                 then calculate for each prime factor

import numba as nb
import numpy as np
from lib.prime_sieve import prime_sieve
from lib.njit_lib import pow

MAXN = 20000 + 1
module = 0x3b9aca07
prime = prime_sieve(MAXN)

@nb.njit
def get_res(prime):
    prime_length = len(prime)
    D = np.ones(MAXN, dtype=np.int64)
    for p in prime:
        factorial_factor_p_number_summation = 0
        for i in range(p, MAXN):
            factorial_factor_p_number = 0
            n = i
            while n:
                n //= p
                factorial_factor_p_number += n
            factorial_factor_p_number_summation += factorial_factor_p_number               
            D[i] *= (pow(p, (i + 1) * factorial_factor_p_number - 2 * factorial_factor_p_number_summation + 1, module) - 1) * pow(p - 1, module - 2, module) % module
            D[i] %= module
    return (np.sum(D) - 1) % module

print(get_res(prime))
