# How many 20 digit numbers n (without any leading zero)
# exist such that no three consecutive digits of n have
# a sum greater than 9?
# ----------------------------------------------------
# Analysis: matrix multiplication

from lib.matrix import Matrix

target = 20
state = [(i, j) for i in range(10) for j in range(i, 10)]
reverse_table = dict((x, i) for i, x in enumerate(state))
state_transfer = Matrix(len(state))
for i in range(len(state)):
    last_digit, last_two_sum = state[i]
    for new_digit in range(10 - last_two_sum):
        state_transfer[reverse_table[(new_digit, last_digit + new_digit)]][i] += 1

multi_transfer = state_transfer ** (target - 2)
print(sum(sum(multi_transfer[i]) for i in range(10, len(state))))
