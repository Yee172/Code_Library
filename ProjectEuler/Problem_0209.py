# A k-input binary truth table is a map from k input bits
# (binary digits, 0 [false] or 1 [true]) to 1 output bit.
# How many 6-input binary truth tables, \tau, satisfy the formula
# \tau(a, b, c, d, e, f) AND \tau(b, c, d, e, f, a XOR (b AND c)) = 0
# for all 6-bit inputs (a, b, c, d, e, f)?
# ----------------------------------------------------
# Analysis: brute force
#           Hint: for each circle, draw a 01-tree

from lib.matrix import Matrix

bit_input = 6

abc_table = [False] * (1 << 3)
for bitmask in range(1 << 3):
    a = bool(bitmask & 1 << 2)
    b = bool(bitmask & 1 << 1)
    c = bool(bitmask & 1 << 0)
    abc_table[bitmask] = a ^ b & c

visited = [False] * (1 << bit_input)

def dfs(bitmask, n=0):
    if visited[bitmask]:
        return n
    connected_bitmask = (bitmask << 1) & (1 << bit_input) - 1 | abc_table[bitmask >> bit_input - 3]
    visited[bitmask] = True
    return dfs(connected_bitmask, n + 1)

state_tranfer = Matrix(2)
state_tranfer[0][0] = 1
state_tranfer[0][1] = 1
state_tranfer[1][0] = 1

res = 1
for bitmask in range(1 << bit_input):
    if not visited[bitmask]:
        n = dfs(bitmask)
        res *= (state_tranfer ** n).trace()

print(res)
