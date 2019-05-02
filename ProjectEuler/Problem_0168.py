# Consider the number 142857. We can right-rotate this
# number by moving the last digit (7) to the front of it,
# giving us 714285.
# It can be verified that 714285 = 5 * 142857.
# This demonstrates an unusual property of 142857:
#    it is a divisor of its right-rotation.
# Find the last 5 digits of the sum of all integers n,
# 10 < n < 10^{100}, that have this property.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 99
k = 1
res = 0
for _ in range(MAXN):
    k *= 10
    for last_digit in range(1, 10):
        tmp = k * last_digit
        for p in range(1, 10):
            tmp -= last_digit
            if not tmp % (10 * p - 1):
                remain_digit = tmp // (10 * p - 1)
                n = remain_digit * 10 + last_digit
                if n // k:
                    res += n

print(res % 10 ** 5)
