# How many n-digit positive integers exist which are
# also an nth power?
# ----------------------------------------------------
# Analysis: brute force

cnt = 0
for a in range(1, 10):
    for b in range(1, 1000):
        n = a ** b
        if len(str(n)) == b:
            cnt += 1

print(cnt)
