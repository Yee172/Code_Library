# The Fibonacci sequence is defined by the recurrence relation:
#    F_{n} = F_{n - 1} + F_{n - 2}, where F_{1} = 1 and F_{2} = 1.
# Given that F_{k} is the first Fibonacci number for
# which the first nine digits AND the last nine digits
# are 1-9 pandigital, find k.
# ----------------------------------------------------
# Analysis: brute force
#           Hint: F_{n} \approx \phi^{n} / \sqrt(5)
#           PS: the loss of accuracy is fatal

from decimal import Decimal

def is_pandigital(s):
    return ''.join(sorted(s)) == '123456789'

module = 10 ** 9
a, b, n = 0, 1, 1

while True:
    a, b, n = b, (a + b) % module, n + 1
    if is_pandigital(str(b)):
        k = Decimal.log10((1 + Decimal.sqrt(Decimal(5))) / 2) * n - Decimal.log10(Decimal.sqrt(Decimal(5)))
        if is_pandigital(str(int(10 ** (k - int(k) + 8)))):
            break

print(n)
