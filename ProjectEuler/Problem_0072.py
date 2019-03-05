# How many elements would be contained in the set of
# reduced proper fractions for d \leq 1000000?
# ----------------------------------------------------
# Analysis: brute force

from lib.phi_sieve import phi_sieve

print(sum(phi_sieve(10 ** 6 + 1, only_phi=True)))
