# A certain type of flexible tile comes in three different
# sizes - 1 × 1, 1 × 2, and 1 × 3 - and in k different
# colours. There is an unlimited number of tiles available
# in each combination of size and colour.
# These are used to tile a closed loop of width 2 and
# length (circumference) n, where n is a positive integer,
# subject to the following conditions:
#    The loop must be fully covered by non-overlapping tiles.
#    It is not permitted for four tiles to have their corners meeting at a single point.
#    Adjacent tiles must be of different colours.
# Let F_{k}(n) be the number of ways the 2 × n loop can
# be tiled subject to these rules when k colours are
# available. (Not all k colours have to be used.) Where
# reflecting horizontally or vertically would give a
# different tiling, these tilings are to be counted separately.
# Find F_{10}(10004003002001) mod 1000004321.
# ----------------------------------------------------
# Analysis: matrix multiplication
#           Hint: loop means that start state equals to its end state

from lib.matrix import Matrix

target = 10004003002001
Matrix.MODULE = 1000004321
color = 10
size = 3
state = [(i, 1, i, 1) for i in range(3)] + [(x, i, y, j) for x, y in [(0, 1), (1, 0), (0, 2), (2, 0), (1, 2), (2, 1), (2, 3)] for i in range(1, size + 1) for j in range(1, size + 1)]
reverse_table = dict((x, i) for i, x in enumerate(state))
state_transfer = Matrix(len(state))
for i in range(len(state)):
    c1, n1, c2, n2 = state[i]
    if c1 == c2:
        if c1 == 2:
            c1 = 3
        for c3 in range(3):
            if c3 == c1:
                continue
            for c4 in range(3):
                if c4 == c1:
                    continue
                if c3 in (0, 1) and c4 in (0, 1):
                    state_transfer[reverse_table[(c3, 1, c4, 1)]][i] += 1
                elif c3 in (0, 1) or c4 in (0, 1):
                    state_transfer[reverse_table[(c3, 1, c4, 1)]][i] += color - 2 - (c1 == 3)
                else:
                    state_transfer[reverse_table[(2, 1, 2, 1)]][i] += color - 2 - (c1 == 3)
                    state_transfer[reverse_table[(2, 1, 3, 1)]][i] += (color - 3) * (color - 4) if c1 == 3 else (color - 2) * (color - 3)
    else:
        for c3 in range(2):
            if c1 != c3 and c2 != c3:
                state_transfer[reverse_table[(c3, 1, c3, 1)]][i] += 1
        state_transfer[reverse_table[(2, 1, 2, 1)]][i] += color - 2 - (c1 > 1) - (c2 > 1)
        c2 -= c2 == 3
        for c3 in range(3):
            for n3 in (1, n1 + 1):
                if n3 > size or (c3 != c1 and n3 > 1) or (c3 != 2 and c3 == c1 and n3 == 1):
                    continue
                for c4 in range(3):
                    for n4 in (1, n2 + 1):
                        if n4 > size or (c4 != c2 and n4 > 1) or (c4 != 2 and c4 == c2 and n4 == 1):
                            continue
                        if c3 != 2 and c3 == c4:
                            continue
                        if n3 == n4 == 1:
                            continue
                        if (c3 == 2 and n3 == 1) or (c4 == 2 and n4 == 1):
                            state_transfer[reverse_table[(c3, n3, c4 + (c3 == 2 and c4 == 2), n4)]][i] += color - 2 - (c1 > 1) - (c2 > 1)
                        else:
                            state_transfer[reverse_table[(c3, n3, c4 + (c3 == 2 and c4 == 2), n4)]][i] += 1

multi_transfer = state_transfer ** target
print((color * multi_transfer[0][0] + color * (color - 1) * sum(multi_transfer[reverse_table[(0, n1, 1, n2)]][reverse_table[(0, n1, 1, n2)]] for n1 in range(1, size + 1) for n2 in range(1, size + 1))) * pow(target, Matrix.MODULE - 2, Matrix.MODULE) % Matrix.MODULE)
