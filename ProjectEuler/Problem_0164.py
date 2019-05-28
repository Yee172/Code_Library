# How many 20 digit numbers n (without any leading zero)
# exist such that no three consecutive digits of n have
# a sum greater than 9?
# ----------------------------------------------------
# Analysis: matrix multiplication

target = 20


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


state = [(i, j) for i in range(10) for j in range(i, 10)]
reverse_table = dict((x, i) for i, x in enumerate(state))
state_transfer = Matrix(len(state))
for i in range(len(state)):
    last_digit, last_two_sum = state[i]
    for new_digit in range(10 - last_two_sum):
        state_transfer.mat[reverse_table[(new_digit, last_digit + new_digit)]][i] += 1

multi_transfer = state_transfer ** (target - 2)
print(sum(sum(multi_transfer.mat[i]) for i in range(10, len(state))))
