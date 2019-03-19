# Let r be the remainder when (a − 1)^{n} + (a + 1)^{n}
# is divided by a^{2}.
# For 3 \leq a \leq 1000, find \sum r_{max}.
# ----------------------------------------------------
# Analysis: brute force
#           Denote A_{n} = (a - 1)^{n} + (a + 1)^{n}, then
#              A_{n} = (2 a) A_{n - 1} - (a^{2} - 1) A_{n - 2}
#           => A_{n} \equiv (2 a) A_{n - 1} + A_{n - 2} (mod a^{2})
#              A_{0} = 2 and A_{1} = 2 a
#           => A_{2 k} \equiv 2 (mod a^{2}) and A_{2 k + 1} \equiv (4 k + 2) a (mod a^{2})
#           Then, we can get that
#              r_{max} = a^{2} - a if a is odd else a^{2} - 2 a, \forall a \geq 3

n, m = 3, 1000

def linear_sum(n, m, d=1):
    return (n + m) * (m - n + d) // d // 2

def square_sum(n, m):
    return m * (m + 1) * (2 * m + 1) // 6 - (n - 1) * n * (2 * n - 1) // 6

print(square_sum(n, m) - linear_sum(n, m) - linear_sum(n + n % 2, m + m % 2, 2))
