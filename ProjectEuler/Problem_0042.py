# Find how many words in the file are triangle words.
# ----------------------------------------------------
# Analysis: brute force

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p042_words.txt'
with open(PROBLEM_FILE, 'r') as f:
    word_list = map(eval, f.read().split(','))

res = 0
for word in word_list:
    value = 0
    for letter in word:
        value += ord(letter.upper()) - 64
    value <<= 1
    p = int(value ** .5)
    res += p * (p + 1) == value

print(res)
