# Find the value of n, 1 < n < 10^{7}, for which \varphi(n)
# is a permutation of n and the ratio n / \varphi(n)
# produces a minimum.
# ----------------------------------------------------
# Analysis: brute force

from lib.phi_sieve import phi_sieve

phi = phi_sieve(10 ** 7, only_phi=True)

print(max(range(2, 10 ** 7), key=lambda n: phi[n] / n if sorted(str(phi[n])) == sorted(str(n)) else 0))
