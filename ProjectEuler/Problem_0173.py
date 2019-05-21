# We shall define a square lamina to be a square
# outline with a square "hole" so that the shape
# possesses vertical and horizontal symmetry.
# Using up to one million tiles how many different
# square laminae can be formed?
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 6
print(sum(int((i * i + MAXN) ** .5) - i >> 1 for i in range(1, MAXN >> 2)))
