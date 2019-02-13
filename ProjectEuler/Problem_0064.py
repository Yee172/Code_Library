# How many continued fractions for N \leq 10000 have
# an odd period?
# ----------------------------------------------------
# Analysis: brute force

def get_period(n):
    s = n ** .5
    p = 1
    q = int(s)
    characteristic = []
    while True:
        x = int(p / (s - q))
        p, q = q, (n - q ** 2) // p
        p, q = q, q * x - p
        if (x, p, q) in characteristic:
            break
        characteristic.append((x, p, q))
    return len(characteristic) & 1

res = 0
for i in range(2, 10001):
    res += int(i ** .5) ** 2 != i and get_period(i)
print(res)
