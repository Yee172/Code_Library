# How many hexadecimal numbers containing at most sixteen
# hexadecimal digits exist with all of the digits 0, 1, and A
# present at least once?
# Give your answer as a hexadecimal number.
# ----------------------------------------------------
# Analysis: matrix multiplication

target = 16


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


n = 4
initial = [13, 2, 0, 0, 0]
state_transfer = Matrix(n + 1)
for i in range(n):
    state_transfer.mat[i][i] = 13 + i
    state_transfer.mat[i + 1][i] = 3 - i
for i in range(2, n):
    state_transfer.mat[n][i] = state_transfer.mat[n - 1][i]
state_transfer.mat[n][n] = 1

multi_transfer = state_transfer ** (target - 1)
print('%X' % sum(multi_transfer.mat[n][i] * initial[i] for i in range(n + 1)))
