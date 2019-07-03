# In the following equation x, y, and n are positive integers.
# \frac{1}{x} + \frac{1}{y} = \frac{1}{n}
# What is the least value of n for which the number of
# distinct solutions exceeds one-thousand?
# ----------------------------------------------------
# Analysis: brute force

from math import log
from queue import PriorityQueue
from lib.prime_sieve import prime_sieve

target = 10 ** 3
modified_target = target * 2 - 1

prime = prime_sieve(int(log(modified_target) / log(3)) * 10)
q = PriorityQueue()
for i, p in enumerate(prime):
    q.put((p, 3, i, 1))

while not q.empty():
    value, modified_solutions, prime_index, occurence_number = q.get()
    if modified_solutions > modified_target:
        break
    q.put((value * prime[prime_index], modified_solutions // (occurence_number << 1 | 1) * (occurence_number + 1 << 1 | 1), prime_index, occurence_number + 1))
    for i in range(prime_index + 1, len(prime)):
        q.put((value * prime[i], modified_solutions * 3, i, 1))

print(value)
