# By replacing each of the letters in the word CARE with
# 1, 2, 9, and 6 respectively, we form a square number:
#    1296 = 36^{2}.
# What is remarkable is that, by using the same digital
# substitutions, the anagram, RACE, also forms a square number:
#    9216 = 96^{2}.
# We shall call CARE (and RACE) a square anagram word pair
# and specify further that leading zeroes are not permitted,
# neither may a different letter have the same digital value
# as another letter.
# A file file containing nearly two-thousand common English
# words, find all the square anagram word pairs (a palindromic
# word is NOT considered to be an anagram of itself).
# What is the largest square number formed by any member
# of such a pair?
# ----------------------------------------------------
# Analysis: brute force

from itertools import permutations

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p098_words.txt'
with open(PROBLEM_FILE, 'r') as f:
    words = list(map(eval, f.read().strip().split(',')))

def is_square(n):
    return int(n ** .5) ** 2 == n

sorted_words = list(map(lambda s: ''.join(sorted(s)), words))
a = list(range(len(words)))
a.sort(key=lambda i: sorted_words[i])

candidates = []

l = ''
word_pair = []
for i in a:
    if sorted_words[i] == l:
        word_pair.append(words[i])
    if sorted_words[i] != l:
        if len(word_pair) > 1:
            candidates.append(word_pair)
        l = sorted_words[i]
        word_pair = [words[i]]
else:
    if len(word_pair) > 1:
        candidates.append(word_pair)

res = 0
for w in candidates:
    s = list(set(w[0]))
    d = dict(zip(s, range(len(s))))
    for mapping in permutations('0123456789', len(s)):
        n = list(map(lambda string: ''.join(map(lambda c: mapping[d[c]], string)), w))
        m = 0
        for each in n:
            if each[0] == '0':
                break
            value = int(each)
            if is_square(value):
                m = max(m, value)
            else:
                break
        else:
            res = max(res, m)

print(res)
