# There exists exactly one Pythagorean triplet
# for which a + b + c = 1000.
# Find the product a * b * c.
# ----------------------------------------------------
# Analysis: brute force

for i in range(1, 1000):
    for j in range(i + 1, 1000):
        k = 1000 - i - j
        if i ** 2 + j ** 2 == k ** 2:
            print(i, j, k, i * j * k)
            exit()
