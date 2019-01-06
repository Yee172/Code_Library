# Work out the alphabetical value for each name,
# multiply this value by its alphabetical position
# in the list to obtain a name score. What is the
# total of all the name scores in the file?
# ----------------------------------------------------
# Analysis: brute force

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p022_names.txt'
with open(PROBLEM_FILE, 'r') as f:
    name_list = map(eval, f.read().split(','))

res = 0
for i, name in enumerate(sorted(name_list)):
    tmp = 0
    for letter in name.upper():
        tmp += ord(letter) - 64
    res += (i + 1) * tmp

print(res)
