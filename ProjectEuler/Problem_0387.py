# A Harshad or Niven number is a number that is divisible
# by the sum of its digits.
# Let's call a Harshad number that, while recursively
# truncating the last digit, always results in a
# Harshad number a right truncatable Harshad number.
# Let's call a Harshad number that, when divided by the
# sum of its digits, results in a prime a strong Harshad number.
# Now take the number 2011 which is prime.
#    When we truncate the last digit from it we get 201,
#    a strong Harshad number that is also right truncatable. 
# Let's call such primes strong, right truncatable Harshad primes.
# Find the sum of the strong, right truncatable Harshad primes less than 10^{14}.
# ----------------------------------------------------
# Analysis: brute force

from lib.prime_sieve import prime_sieve

MAXN = 10 ** 7
M = 14
is_prime, prime = prime_sieve(MAXN, False, function_is_prime=True)

def is_Harshad_number(n):
    s = sum(map(int, str(n)))
    return False if n % s else s

res = 0

truncatable_Harshad_number = list(range(1, 10))
for i in range(M - 2):
    new_truncatable_Harshad_number = []
    strong_Harshad_number = []
    for x in truncatable_Harshad_number:
        x *= 10
        for i in range(10):
            y = x + i
            s = is_Harshad_number(y)
            if s:
                new_truncatable_Harshad_number.append(y)
                if is_prime(y // s):
                    strong_Harshad_number.append(y)
    truncatable_Harshad_number = new_truncatable_Harshad_number
    for x in strong_Harshad_number:
        x *= 10
        for i in [1, 3, 7, 9]:
            y = x + i
            if is_prime(y):
                res += y

print(res)
