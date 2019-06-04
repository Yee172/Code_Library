# At Euler University, each of the n students (numbered
# from 1 to n) occupies a bed in the dormitory and uses
# a desk in the classroom.
# Some of the beds are in private rooms which a student
# occupies alone, while the others are in double rooms
# occupied by two students as roommates. Similarly, each
# desk is either a single desk for the sole use of one
# student, or a twin desk at which two students sit
# together as desk partners.
# We represent the bed and desk sharing arrangements each
# by a list of pairs of student numbers. For example,
#    with n = 4, if (2, 3) represents the bed pairing and
#    (1, 3) (2, 4) the desk pairing, then students 2 and 3
#    are roommates while 1 and 4 have single rooms, and
#    students 1 and 3 are desk partners, as are students 2 and 4.
# The new chancellor of the university decides to change
# the organisation of beds and desks:
# he will choose a permutation \sigma of the numbers 1, 2, ..., n
# and each student k will be given both the bed and the
# desk formerly occupied by student number \sigma(k).
# The students agree to this change, under the conditions that:
#    1. Any two students currently sharing a room will still be roommates.
#    2. Any two students currently sharing a desk will still be desk partners.
# The downloadable text files beds.txt and desks.txt
# contain pairings for n = 500. Each pairing is written
# on its own line, with the student numbers of the two
# roommates (or desk partners) separated with a comma.
# With these pairings, find the number of permutations
# that satisfy the students' conditions.
# Give your answer modulo 999999937.
# ----------------------------------------------------
# Analysis: disjoint set union

import sys
from collections import defaultdict
from math import factorial
from lib.disjoint_set_union import disjoint_set_union

PATH = sys.path[0]
PROBLEM_FILE_BEDS = PATH + '/extra_problem_files/p673_beds.txt'
PROBLEM_FILE_DESKS = PATH + '/extra_problem_files/p673_desks.txt'

with open(PROBLEM_FILE_BEDS, 'r') as f:
    beds = list(map(eval, f.read().strip().split('\n')))

with open(PROBLEM_FILE_DESKS, 'r') as f:
    desks = list(map(eval, f.read().strip().split('\n')))

n = 500
module = 0x3b9ac9c1
dsu = disjoint_set_union(n)

paired_beds = set()
paired_desks = set()

for x, y in beds:
    x, y = x - 1, y - 1
    dsu.union_father(x, y)
    paired_beds.add(x)
    paired_beds.add(y)

for x, y in desks:
    x, y = x - 1, y - 1
    dsu.union_father(x, y)
    paired_desks.add(x)
    paired_desks.add(y)

population = [[0] * 2 for i in range(n)]
for son in range(n):
    father = dsu.get_father(son)
    if not population[father][1]:
        is_single_bed = son not in paired_beds
        is_single_desk = son not in paired_desks
        population[father][1] = is_single_bed << 1 | is_single_desk
    population[father][0] += 1

clans = defaultdict(int)
for x, y in population:
    if x:
        if x & 1:
            y = 1
        clans[(x, y)] += 1

res = 1
for x, y in clans:
    size = clans[(x, y)]
    res *= factorial(size)
    if x & 1 ^ 1:
        res *= (2 if y else x) ** size
    res %= module

print(res)
