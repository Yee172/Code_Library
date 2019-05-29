# A certain type of tile comes in three different sizes -
# 1 × 1, 1 × 2, and 1 × 3 - and in four different colours:
# blue, green, red and yellow. There is an unlimited
# number of tiles available in each combination of size
# and colour.
# These are used to tile a 2 × n rectangle, where n is a
# positive integer, subject to the following conditions:
#    The rectangle must be fully covered by non-overlapping tiles.
#    It is not permitted for four tiles to have their corners meeting at a single point.
#    Adjacent tiles must be of different colours.
# Let F(n) be the number of ways the 2 × n rectangle can
# be tiled subject to these rules. Where reflecting
# horizontally or vertically would give a different
# tiling, these tilings are to be counted separately.
# Find F(10^{16}) mod 1000004321.
# ----------------------------------------------------
# Analysis: matrix multiplication

target = 10 ** 16
module = 1000004321
color = 4
size = 3


class Matrix:
    def __init__(self, size):
        self.size = size
        self.mat = [[0] * size for _ in range(size)]

    def __mul__(self, another):
        assert(self.size == another.size)
        res = Matrix(self.size)
        for i in range(self.size):
            for k in range(self.size):
                if self.mat[i][k]:
                    for j in range(self.size):
                        res.mat[i][j] += self.mat[i][k] * another.mat[k][j]
                        res.mat[i][j] %= module
        return res

    def __pow__(self, exponent):
        assert(isinstance(exponent, int) and exponent >= 0)
        res = Matrix(self.size)
        for i in range(self.size):
            res.mat[i][i] = 1
        tmp = res * self
        while exponent:
            if exponent & 1:
                res *= tmp
            tmp *= tmp
            exponent >>= 1
        return res


state = [(0, 1, 0, 1)] + [(0, i, 1, j) for i in range(1, size + 1) for j in range(1, size + 1)]
reverse_table = dict((x, i) for i, x in enumerate(state))
state_transfer = Matrix(len(state))
state_transfer.mat[0][0] = color - 1
state_transfer.mat[1][0] = (color - 1) * (color - 2)
for i in range(1, len(state)):
    state_transfer.mat[0][i] = color - 2
    n1, n2 = state[i][1::2]
    n1, n2 = n1 + 1, n2 + 1
    if n1 <= size:
        state_transfer.mat[reverse_table[(0, n1, 1, 1)]][i] = color - 2
    if n2 <= size:
        state_transfer.mat[reverse_table[(0, 1, 1, n2)]][i] = color - 2
    if n1 <= size and n2 <= size:
        state_transfer.mat[reverse_table[(0, n1, 1, n2)]][i] = 1

initial = [color, color * (color - 1)] + [0] * (len(state) - 2)
multi_transfer = state_transfer ** (target - 1)
print(sum(multi_transfer.mat[i][j] * initial[j] for i in range(len(state)) for j in range(len(state))) % module)
