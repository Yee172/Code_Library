# Find the sum of all 0 to 9 pandigital numbers with
# the following property.
# Let d_{i} be the i-th digit, and we have
#    d_{2} d_{3} d_{4}  is divisible by 2
#    d_{3} d_{4} d_{5}  is divisible by 3
#    d_{4} d_{5} d_{6}  is divisible by 5
#    d_{5} d_{6} d_{7}  is divisible by 7
#    d_{6} d_{7} d_{8}  is divisible by 11
#    d_{7} d_{8} d_{9}  is divisible by 13
#    d_{8} d_{9} d_{10} is divisible by 17
# ----------------------------------------------------
# Analysis: brute force
#           d_{4} must be divisible by 2
#           d_{6} must be 5 because d_{6} d_{7} d_{8} is divisible by 11
#              if d_{6} is 0, then we get d_{7} = d_{8} which is a contradiction

from itertools import permutations

prime = [0, 2, 3, 5, 7, 11, 13, 17]

res = 0
for p in permutations('0123456789'):
    if p[3] in '13579' or not p[5] == '5':
        continue
    p = ''.join(p)
    flag = False
    for i in range(7, 0, -1):
        flag |= int(p[i : i + 3]) % prime[i]
        if flag:
            break
    if not flag:
        res += int(p)

print(res)
