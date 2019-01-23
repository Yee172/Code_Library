# Find the largest palindrome made from the
# product of two 3-digit numbers.
# ----------------------------------------------------
# Analysis: brute force

def check(n):
    s = str(n)
    return s == s[::-1]

def get_res():
    a = []
    for i in range(999, 99, -1):
        for j in range(i, 99, -1):
            a.append(i * j)
    a.sort()
    for x in a[::-1]:
        if check(x):
            return x

print(get_res())
