# Let y_{0}, y_{1}, y_{2}, ... be a sequence of random
# unsigned 32 bit integers.
# For the sequence xi the following recursion is given:
#    1. x_{0} = 0 and
#    2. x_{i} = x_{i - 1} | y_{i - 1}, for i > 0.
# It can be seen that eventually there will be an index
# N such that x_{i} = 2^{32} -1 for all i \geq N.
# Find the expected value of N.
# Give your answer rounded to 10 digits after the decimal point.
# ----------------------------------------------------
# Analysis: brute force
#           E = \frac{1}{2}^{32} * \sum_{i = 1}^{\infty} i * ((1 + \frac{2^{i - 1} - 1}{2^{i - 1}})^{32} - (1 + \frac{2^{i - 2} - 1}{2^{i - 2}})^{32})
#             = \sum_{i = 0}^{\infty} (1 - (1 - \frac{1}{2^{i}})^{32})

print('%.10f' % sum(1 - (1 - 1 / 2 ** i) ** 32 for i in range(50)))
