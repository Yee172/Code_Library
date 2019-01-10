# What is the index of the first term in the
# Fibonacci sequence to contain 1000 digits?
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 999
a, b = 1, 1
i = 2
while True:
    a, b = b, a + b
    i += 1
    if b >= MAXN:
        break

print(i)
