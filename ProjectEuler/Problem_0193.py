# A positive integer n is called squarefree, if no
# square of a prime divides n.
# How many squarefree numbers are there below 2^{50}?
# ----------------------------------------------------
# Analysis: inclusion-exclusion principle, mobius function

from lib.mobius_mu_sieve import mobius_mu_sieve

MAXN = 2 ** 50 - 1
print(sum(MAXN // i ** 2 * f for i, f in enumerate(mobius_mu_sieve(int(MAXN ** .5) + 1, True)) if f))
