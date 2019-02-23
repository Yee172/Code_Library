# Find the number of characters saved by writing each
# of these numbers written in valid Roman numerals in
# their minimal form.
# ----------------------------------------------------
# Analysis: brute force

increase_table = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
mapping = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p089_roman.txt'
with open(PROBLEM_FILE, 'r') as f:
    roman = f.read().strip().split()

def roman2int(s):
    if not s:
        return 0
    a = s[0]
    b = s[1] if len(s) > 1 else None
    for p in range(0, 6, 2):
        if a == increase_table[p]:
            if b in increase_table[p + 1: p + 3]:
                return mapping[b] - mapping[a] + roman2int(s[2:])
    return mapping[a] + roman2int(s[1:])

def int2roman(n):
    if n < 4:
        return 'I' * n
    for p, x in enumerate(increase_table[: 0: -1]):
        if n >= mapping[x]:
            return x + int2roman(n - mapping[x])
        m = increase_table[4 - (p >> 1 << 1)]
        if n >= mapping[x] - mapping[m]:
            return m + x + int2roman(n - mapping[x] + mapping[m])

print(sum(map(len, roman)) - sum(map(len, map(int2roman, map(roman2int, roman)))))
