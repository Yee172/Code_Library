# A common security method used for online banking is
# to ask the user for three random characters from a
# passcode.
#    For example, if the passcode was 531278, they may
#    ask for the 2nd, 3rd, and 5th characters;
#    the expected reply would be: 317.
# Given that the three characters are always asked for
# in order, analyse the file so as to determine the
# shortest possible secret passcode of unknown length.
# ----------------------------------------------------
# Analysis: brute force

from itertools import product

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p079_keylog.txt'
with open(PROBLEM_FILE, 'r') as f:
    keylog = list(map(lambda n: list(map(int, str(n))), set(map(int, f.read().strip().split()))))

res = []
l = 0

def find_missing(log):
    j = 0
    for x in log:
        while j < l and res[j] != x:
            j += 1
        if j == l:
            yield x

def check():
    for log in keylog:
        j = 0
        for x in log:
            while j < l and res[j] != x:
                j += 1
            if j == l:
                return False
    return True

while not check():
    front = -1
    for log in keylog:
        if front == -1:
            for m in find_missing(log):
                front = m
                break
        else:
            missing = list(find_missing(log))
            if len(missing) < 2:
                continue
            for m in missing[1:]:
                if front == m:
                    front = missing[0]
    res.append(front)
    l += 1

print(''.join(map(str, res)))
