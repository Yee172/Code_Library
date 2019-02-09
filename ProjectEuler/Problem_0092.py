# A number chain is created by continuously adding the
# square of the digits in a number to form a new number
# until it has been seen before.
# What is most amazing is that EVERY starting number
# will eventually arrive at 1 or 89.
# How many starting numbers below ten million will
# arrive at 89?
# ----------------------------------------------------
# Analysis: brute force

res = 0
MAXN = 10 ** 7
d = set([89])

def get_next(n):
    r = 0
    while n:
        n, x = divmod(n, 10)
        r += x ** 2
    return r

for i in range(1, MAXN):
    n = i
    while n != 1:
        n = get_next(n)
        if n in d:
            d.add(i)
            res += 1
            break

print(res)
