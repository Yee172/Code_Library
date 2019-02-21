# A file containing one thousand lines with a base/exponent
# pair on each line, determine which line number has the
# greatest numerical value.
# ----------------------------------------------------
# Analysis: brute force

from math import log

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p099_base_exp.txt'
with open(PROBLEM_FILE, 'r') as f:
    base_exp = list(map(lambda a: list(map(int, a.split(','))), f.read().strip().split()))

print(max(range(len(base_exp)), key=lambda i: base_exp[i][1] * log(base_exp[i][0])) + 1)
