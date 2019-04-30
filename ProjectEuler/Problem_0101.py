# If we are presented with the first k terms of a sequence
# it is impossible to say with certainty the value of the
# next term, as there are infinitely many polynomial
# functions that can model the sequence.
# We shall define OP(k, n) to be the n-th term of the optimum
# polynomial generating function for the first k terms of
# a sequence. It should be clear that OP(k, n) will accurately
# generate the terms of the sequence for n \leq k, and
# potentially the first incorrect term (FIT) will be OP(k, k+1);
# in which case we shall call it a bad OP (BOP).
# As a basis, if we were only given the first term of
# sequence, it would be most sensible to assume constancy;
# that is, for n \geq 2, OP(1, n) = u_{1}.
# Consider the following tenth degree polynomial generating function:
#    u_{n} = 1 - n + n^{2} - n^{3} + n^{4} - n^{5} + n^{6} - n^{7} + n^{8} - n^{9} + n^{10}
# Find the sum of FITs for the BOPs.
# ----------------------------------------------------
# Analysis: lagrange interpolation

from functools import reduce

MAXN = 10 + 1

def f(n):
    return 1 - n + n ** 2 - n ** 3 + n ** 4 - n ** 5 + n ** 6 - n ** 7 + n ** 8 - n ** 9 + n ** 10

def lagrange_interpolation(x):
    l = len(x)

    def L(x, j):
        return reduce(int.__mul__, [x - i for i in range(1, l + 1) if i != j], 1)

    def q(j):
        return reduce(int.__mul__, [(j - i) for i in range(1, l + 1) if i != j], 1)

    return lambda n: int(sum(L(n, i + 1) * x[i] / q(i + 1) for i in range(l)))

r = 0
a = [f(n) for n in range(1, MAXN + 1)]
for i in range(1, MAXN):
    u = lagrange_interpolation(a[:i])
    j = i + 1
    while u(j) == f(j):
        j += 1
    r += u(j)

print(r)
