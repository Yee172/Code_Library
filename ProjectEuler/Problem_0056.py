# What is the maximum digital sum of the form a^{b}?
# where a, b < 100.
# ----------------------------------------------------
# Analysis: brute force

res = 0
for a in range(2, 100):
    for b in range(2, 100):
        res = max(res, sum(map(int, str(a ** b))))

print(res)
