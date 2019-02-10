# Find the last ten digits of 28433 \times 2^{7830457} + 1.
# ----------------------------------------------------
# Analysis: brute force

MOD = 10 ** 10
print((28433 * pow(2, 7830457, MOD) + 1) % MOD)
