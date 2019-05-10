# Find the sum of all the numbers less than 10^{8} that
# are both palindromic and can be written as the sum of
# consecutive squares.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 8

def is_palindromic(s):
    return s == s[::-1]

length = int(MAXN ** .5) + 1
summation = [n * (n + 1) * (2 * n + 1) // 6 for n in range(length)]
res = set()
for i in range(length):
    for j in range(i + 2, length):
        n = summation[j] - summation[i]
        if n < MAXN:
            if is_palindromic(str(n)):
                res.add(n)
        else:
            break

print(sum(res))
