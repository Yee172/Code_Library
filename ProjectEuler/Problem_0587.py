# A square is drawn around a circle. We shall call the
# left bottom corner region the L-section.
# If n circles are placed next to each other horizontally,
# a rectangle is drawn around the n circles, and a line
# is drawn from the bottom left to the top right, what
# is the least value of n for which the concave triangle
# occupies less than 0.1% of the L-section?
# ----------------------------------------------------
# Analysis: adaptive Simpson integral

from ProjectEuler.lib.adaptive_Simpson_integral import adaptive_Simpson_integral

pi = __import__('math').pi
radius = 10 ** 4
q = (4 - pi) * radius ** 2 / 4
ratio = 0.001
upper_bound = q * ratio
f = lambda x: (radius ** 2 - x ** 2) ** .5

def check(n):
    y = (-radius * n * (n - 1) - radius * (2 * n) ** .5) / (n ** 2 + 1)
    x = n * (y + radius) - radius
    return ((y + radius) ** 2 * n / 2 - radius * x - adaptive_Simpson_integral(f, x, 0)) < upper_bound

left, right = 1, 10 ** 4
while left < right:
    middle = left + right >> 1
    if check(middle):
        right = middle
    else:
        left = middle + 1

print(left)
