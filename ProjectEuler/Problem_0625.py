# G(N) = \sum_{j = 1}^{N} \sum_{i = 1}^{j} gcd(i, j).
# Find G(10^{11}). Give your answer modulo 998244353.
# ----------------------------------------------------
# Analysis: Dujiao sieve
#           Hint: G(N) = \sum_{j = 1}^{N} (j * \sum_{i = 1}^{N // j} \phi(i))

from collections import defaultdict
from ProjectEuler.lib.phi_sieve import phi_sieve

target = 10 ** 11
sqrt_target = int(target ** .5) + 1
MAXN = int(target ** (2 / 3)) + 1
module = 0x3b800001
phi = phi_sieve(MAXN, True)

pre_sum_phi_1 = [0] * MAXN
pre_sum_phi_2 = defaultdict(int)
for i in range(1, MAXN):
    pre_sum_phi_1[i] = (pre_sum_phi_1[i - 1] + phi[i]) % module

def phi_sum(n):
    if n < MAXN:
        return pre_sum_phi_1[n]
    else:
        if pre_sum_phi_2[n]:
            return pre_sum_phi_2[n]
    res = 0
    p = 2
    while p <= n:
        q = n // (n // p)
        res += (q - p + 1) * phi_sum(n // p)
        res %= module
        p = q + 1
    res = (n * (n + 1) // 2 - res) % module
    if n >= MAXN:
        pre_sum_phi_2[n] = res
    return res

res = 0
p = 1
while p <= target:
    q = target // (target // p)
    res += (p + q) * (q - p + 1) // 2 * phi_sum(target // p)
    res %= module
    p = q + 1

print(res)
