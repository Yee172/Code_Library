# Let S(A) represent the sum of elements in set A of size n.
# We shall call it a special sum set if for any two non-empty
# disjoint subsets, B and C, the following properties are true:
#    1. S(B) \neq S(C); that is, sums of subsets cannot be equal.
#    2. If B contains more elements than C then S(B) > S(C).
# Using a 4K text file with one-hundred sets containing
# seven to twelve elements (the two examples given above
# are the first two sets in the file), identify all the
# special sum sets, A_{1}, A_{2}, ..., A_{k}, and find
# the value of S(A_{1}) + S(A_{2}) + ... + S(A_{k}).
# ----------------------------------------------------
# Analysis: brute force

from collections import defaultdict

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p105_sets.txt'
with open(PROBLEM_FILE, 'r') as f:
    sets = map(eval, f.read().strip().split('\n'))

def check(A):
    A = sorted(A)
    length = len(A)
    prefix_sum = [0] * length
    prefix_sum[0] = A[0]
    for i in range(1, length):
        prefix_sum[i] = prefix_sum[i - 1] + A[i]
    for i in range(length - 1 >> 1):
        if prefix_sum[length - 1] - prefix_sum[length - 2 - i] >= prefix_sum[i + 1]:
            return False
    d = defaultdict(bool)
    for mask in range(1, 1 << length):
        subset_sum = 0
        for i in range(length):
            if mask & 1 << i:
                subset_sum += A[i]
        if d[subset_sum]:
            return False
        d[subset_sum] = True
    return True

print(sum(sum(each_set) for each_set in sets if check(each_set)))
