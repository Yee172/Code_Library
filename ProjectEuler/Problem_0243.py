# A positive fraction whose numerator is less than its
# denominator is called a proper fraction.
# We shall call a fraction that cannot be cancelled
# down a resilient fraction.
# Furthermore we shall define the resilience of a denominator,
# R(d), to be the ratio of its proper fractions that are
# resilient.
# For example, R(12) = 4 / 11.
# Find the smallest denominator d, having a resilience
# R(d) < 15499 / 94744.
# ----------------------------------------------------
# Analysis: brute force
#           According to the property of phi function,
#           we can see that we should first find the minimum
#           consecutive prime production satisfies the condition,
#           then enumerate the multiply of the second minimum
#           consecutive prime production to get the result.
#           Hint: Based on phi(n) = n \prod_{p | n, p prime} (1 - 1 / p),
#                 we can see that
#                 phi(n * d) / (d * n - 1) < phi(n) / (n - 1)
#                    if d is a prime divisor of n
#                 phi(n * p) / (p * n - 1) < phi(n * d) / (n * d - 1)
#                    if p a prime that prime with n and d is a prime divisor of n

from ProjectEuler.lib.prime_sieve import prime_sieve

prime = prime_sieve(30)
p, q = 15499, 94744

x, y = 1, 1
upper_limit = 0
for each in prime:
    x *= each - 1
    y *= each
    if x * q < (y - 1) * p:
        x //= each - 1
        y //= each
        upper_limit = each
        break

w, z = x, y
for i in range(2, each):
    w, z = w + x, z + y
    if w * q < (z - 1) * p:
        break

print(z)
