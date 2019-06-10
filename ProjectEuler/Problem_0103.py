# Let S(A) represent the sum of elements in set A of size n.
# We shall call it a special sum set if for any two non-empty
# disjoint subsets, B and C, the following properties are true:
#    1. S(B) \neq S(C); that is, sums of subsets cannot be equal.
#    2. If B contains more elements than C then S(B) > S(C).
# If S(A) is minimised for a given n, we shall call it
# an optimum special sum set. The first five optimum
# special sum sets are given below.
#    n = 1: {1}
#    n = 2: {1, 2}
#    n = 3: {2, 3, 4}
#    n = 4: {3, 5, 6, 7}
#    n = 5: {6, 9, 11, 12, 13}
# It seems that for a given optimum set, A = {a_{1}, a_{2}, ..., a_{n}},
# the next optimum set is of the form B = {b, a_{1} + b, a_{2} + b, ..., a_{n} + b},
# where b is the "middle" element on the previous row.
# By applying this "rule" we would expect the optimum set for
# n = 6 to be A = {11, 17, 20, 22, 23, 24}, with S(A) = 117.
# However, this is not the optimum set, as we have merely
# applied an algorithm to provide a near optimum set.
# The optimum set for n = 6 is A = {11, 18, 19, 20, 22, 25},
# with S(A) = 115 and corresponding set string: 111819202225.
# Given that A is an optimum special sum set for n = 7,
# find its set string.
# ----------------------------------------------------
# Analysis: brute force

target = 7

def check_propertie2(A):
    length = len(A)
    prefix_sum = [0] * length
    prefix_sum[0] = A[0]
    for i in range(1, length):
        prefix_sum[i] = prefix_sum[i - 1] + A[i]
    for i in range(length - 1 >> 1):
        if prefix_sum[length - 1] - prefix_sum[length - 2 - i] >= prefix_sum[i + 1]:
            return False
    return True

A = [1]

def get_next_A():
    global A
    step = A[0]
    middle = A[len(A) >> 1]
    _A = [middle] + [middle + x for x in A]
    A = _A
    search_bound = A[1]
    SA = [sum(A)]
    lengthA = len(A)

    d = set()
    d.add(0)
    d.add(middle)

    def dfs(a, length):
        global A
        if length == lengthA:
            if check_propertie2(a) and sum(a) < SA[0]:
                SA[0] = sum(a)
                A = a
        for x in range(a[-1] + 1, a[-1] + step):
            if not any(each_sum + x in d for each_sum in d):
                addition = [each_sum + x for each_sum in d]
                for each in addition:
                    d.add(each)
                dfs(a + [x], length + 1)
                for each in addition:
                    d.remove(each)

    for p in range(search_bound, search_bound + 5):
        d.add(p)
        d.add(p + middle)
        dfs([middle, p], 2)
        d.remove(p)
        d.remove(p + middle)

for i in range(target - 1):
    get_next_A()

print(''.join(map(str, A)))
