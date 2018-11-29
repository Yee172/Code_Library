# last ten digits of \sum_{i = 1}^{1000} i^{i}
# --------------------------------------------
# Analysis: brute force

MOD = 10 ** 10
s = 0
for i in range(1, 1001):
    s += pow(i, i, MOD)
    s %= MOD
print(s)
