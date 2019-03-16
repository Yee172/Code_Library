# In the context of formal languages, any finite sequence
# of letters of a given alphabet \Sigma is called a word
# over \Sigma. We call a word incomplete if it does not
# contain every letter of \Sigma.
# Given an alphabet \Sigma of \alpha letters, we define
# I(\alpha, n) to be the number of incomplete words over
# \Sigma with a length not exceeding n.
# Find I(10^{7}, 10^{12}).
#    Give your answer modulo 1000000007.
# ----------------------------------------------------
# Analysis: Stirling numbers of the second kind
#           Define i(\alpha, n) to be the number of
#              incomplete words over \Sigma with a
#              length of n
#           When n < \alpha, all words are incomplete
#           When n \geq \alpha, there are exactly S(n, \alpha) * \alpha! words are not incomplete,
#              which means that there are \alpha^{n} - S(n, \alpha) * \alpha! words are incomplete,
#              where S(n, k) is the stirling number of the second kind
#           Therefore, I(\alpha, n) = \sum_{j = 0}^{n} i(\alpha, j)
#                                   = \sum_{j = 0}^{\alpha - 1} i(\alpha, j) + \sum_{j = \alpha}^{n} i(\alpha, j)
#                                   = \sum_{j = 0}^{\alpha - 1} \alpha^{j} + \sum_{j = \alpha}^{n} (\alpha^{j} - S(j, \alpha) * \alpha!)
#                                   = \sum_{j = 0}^{n} \alpha^{j} - \sum_{j = \alpha}^{n} (S(j, \alpha) * \alpha!)
#                                   = \sum_{j = 0}^{n} \alpha^{j} - \sum_{j = \alpha}^{n} \sum_{k = 0}^{\alpha} ((-1)^{k} * \binom{\alpha, k} * (\alpha - k)^{j})
#                                   = \sum_{j = 0}^{n} \alpha^{j} - \sum_{k = 0}^{\alpha} (((-1)^{k} * \binom{\alpha, k}) * \sum_{j = \alpha}^{n} (\alpha - k)^{j})

MOD = 0x3b9aca07
MAXN = 10 ** 7 + 1

factorial = [0] * MAXN
mod_inverse = [0] * MAXN
factorial_inverse = [0] * MAXN
factorial[0] = factorial[1] = mod_inverse[1] = factorial_inverse[0] = factorial_inverse[1] = 1

for i in range(2, MAXN):
    factorial[i] = factorial[i - 1] * i % MOD
    mod_inverse[i] = (MOD - MOD // i) * mod_inverse[MOD % i] % MOD;
    factorial_inverse[i] = factorial_inverse[i - 1] * mod_inverse[i] % MOD

def power_sum(base, start, end):
    if base == 1:
        return end - start + 1
    return (pow(base, end + 1, MOD) - pow(base, start, MOD)) * mod_inverse[base - 1] % MOD

def binomial(n, m):
    return 0 if m > n else factorial[n] * factorial_inverse[n - m] * factorial_inverse[m] % MOD

def pm(k):
    return MOD - 1 if k & 1 else 1

def I(alpha, n):
    r = 0
    for k in range(alpha):
        r += pm(k) * binomial(alpha, k) * power_sum(alpha - k, alpha, n)
        r %= MOD
    r = (power_sum(alpha, 0, n) - r) % MOD
    return r

print(I(10 ** 7, 10 ** 12))
