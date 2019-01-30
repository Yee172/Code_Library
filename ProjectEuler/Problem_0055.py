# How many Lychrel numbers are there below ten-thousand?
# ----------------------------------------------------
# Analysis: brute force

res = 0
for n in range(1, 10000):
    for _ in range(50):
        n += int(str(n)[::-1])
        s = str(n)
        if s == s[::-1]:
            break
    else:
        res += 1

print(res)
