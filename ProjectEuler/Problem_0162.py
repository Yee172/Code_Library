# How many hexadecimal numbers containing at most sixteen
# hexadecimal digits exist with all of the digits 0, 1, and A
# present at least once?
# Give your answer as a hexadecimal number.
# ----------------------------------------------------
# Analysis: matrix multiplication

from lib.matrix import Matrix

target = 16
n = 4
initial = [13, 2, 0, 0, 0]
state_transfer = Matrix(n + 1)
for i in range(n):
    state_transfer[i][i] = 13 + i
    state_transfer[i + 1][i] = 3 - i
for i in range(2, n):
    state_transfer[n][i] = state_transfer[n - 1][i]
state_transfer[n][n] = 1

multi_transfer = state_transfer ** (target - 1)
print('%X' % sum(multi_transfer[n][i] * initial[i] for i in range(n + 1)))
