# Find the sum of all double-base palindromes
# less than one million.
# ----------------------------------------------------
# Analysis: brute force

MAXN = 10 ** 6

def is_palindrome(s):
    return s[::-1] == s

s = 0
for i in range(1, MAXN):
    s += i * (is_palindrome(str(i)) and is_palindrome(str(bin(i)[2:])))
print(s)
