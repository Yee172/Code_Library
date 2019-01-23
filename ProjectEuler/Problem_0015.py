# Only being able to move to the right and down,
# how many routes are there through a 20×20 grid
# from the top left corner to the bottom right corner?
# ----------------------------------------------------
# Analysis: binomial

def binomial(n, k):
    if k > n:
        return 0
    res = 1
    for i in range(k):
        res *= n - i
        res //= i + 1
    return res

print(binomial(40, 20))
