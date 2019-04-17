# A natural number, N, that can be written as the sum
# and product of a given set of at least two natural
# numbers is called a product-sum number.
# For a given set of size, k, we shall call the smallest
# N with this property a minimal product-sum number.
# What is the sum of all the minimal product-sum
# numbers for 2 \leq k \leq 12000? (same number count once)
# ----------------------------------------------------
# Analysis: brute force

from queue import PriorityQueue

MAXK = 12000

minimal_product_sum_number = [0] * (MAXK + 1)
minimal_product_sum_number[0] = 0
minimal_product_sum_number[1] = 1
count = MAXK - 1
q = PriorityQueue()
for i in range(2, MAXK + 1):
    q.put((i, i, 1, 1))

while count:
    p, s, n, k = q.get()
    if not minimal_product_sum_number[k]:
        minimal_product_sum_number[k] = p
        count -= 1
    for i in range(2, MAXK + 1):
        next_p, next_s, next_n = p * i, s + i, n + 1
        next_k = next_p - next_s + next_n
        if next_k > MAXK:
            break
        q.put((next_p, next_s, next_n, next_k))

print(sum(set(minimal_product_sum_number[2:])))
