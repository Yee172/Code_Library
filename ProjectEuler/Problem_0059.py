# Using a file containing the encrypted ASCII codes,
# and the knowledge that the plain text must contain
# common English words, decrypt the message and find
# the sum of the ASCII values in the original text
# as the encryption key consists of three lower case
# characters with XOR encryption method.
# ----------------------------------------------------
# Analysis: brute force

from itertools import product

import sys
PATH = sys.path[0]
PROBLEM_FILE = PATH + '/extra_problem_files/p059_cipher.txt'
with open(PROBLEM_FILE, 'r') as f:
    encrypted = list(map(int, f.read().strip().split(',')))

for password in product(*([range(97, 123)] * 3)):
    index = 0
    original = []
    for code in encrypted:
        original.append(code ^ password[index])
        index = (index + 1) % 3
    plain_text = ''.join(map(chr, original))
    if 'that' in plain_text and 'and' in plain_text and 'the' in plain_text:
        print(plain_text)
        print(sum(original))
