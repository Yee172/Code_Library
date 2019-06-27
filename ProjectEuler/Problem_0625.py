# G(N) = \sum_{j = 1}^{N} \sum_{i = 1}^{j} gcd(i, j).
# Find G(10^{11}). Give your answer modulo 998244353.
# ----------------------------------------------------
# Analysis: sieve of Dujiao
#           Hint: G(N) = \sum_{j = 1}^{N} (j * \sum_{i = 1}^{N // j} \phi(i))

from lib.phi_sum import phi_sum

target = 10 ** 11
module = 0x3b800001
dfs = phi_sum(target, False, module=module)

res = 0
p = 1
while p <= target:
    q = target // (target // p)
    res += (p + q) * (q - p + 1) // 2 * dfs(target // p)
    res %= module
    p = q + 1

print(res)
