# Let T(n, m) be the number of m-tuples of positive
# integers such that the sum of any two neighbouring
# elements of the tuple is \leq n.
# Find T(5000, 1e12) mod 1000000007.
# ----------------------------------------------------
# Analysis: Berlekamp-Massey Algorithm
#           Let D(t, m) be the number of m-tuples of positive integers start with t, we get
#              D(1, m) = D(1, m - 1) + \cdots + D(n - 4, m - 1) + D(n - 3, m - 1) + D(n - 2, m - 1)
#              D(2, m) = D(1, m - 1) + \cdots + D(n - 4, m - 1) + D(n - 3, m - 1)
#              D(3, m) = D(1, m - 1) + \cdots + D(n - 4, m - 1)
#              \vdots
#              D(n - 2, m) = D(1, m)
#           Then we have 
#              T(n, m) = D(1, m) + D(2, m) + D(3, m) + \cdots + D(n - 2, m)
#                      = (n - 2)D(1, m - 1) + (n - 3)D(2, m - 1) + \cdots + D(n - 2, m - 1)
#           Keep doing this process, we can see that this follows the prefix sum similar property
#           Let A = \left [ \begin{matrix}
#                           1, 1, 1, \ldots, 1, 1
#                           1, 1, 1, \ldots, 1, 0
#                           \vdots, \vdots, \vdots, \ddots, \vdots, \vdots
#                           1, 1, 0, \ldots, 0, 0
#                           1, 0, 0, \ldots, 0, 0
#                   \end{matrix} \right ]
#           be a (n - 1) \times (n - 1) matrix,
#           then the element at the upper left corner of (A ** (m + 1)) is the answer
#           However, the time complicity is O(n^{3} \log(m)), which would be large when n = 5000
#           Thus, Berlekamp-Massey Algorithm would be implemented to reduce time complicity into O(n^{2} \log(m))
#           By the way, using PyPy3 will be much faster.

from lib.linear_recursion import LinearRecursion

modulo = 0x3b9aca07

target_n = 5000
target_m = 10 ** 12

def T(n, m):
    p = [1] * (n - 1)
    if m < n << 1:
        for i in range(m):
            t = [0] * (n - 1)
            for j in range(n - 1):
                t[j] = (t[j - 1] + p[j]) % modulo
            p = t[:: -1]
        return p[0]
    x = [1]
    for i in range(n << 1):
        t = [0] * (n - 1)
        for j in range(n - 1):
            t[j] = (t[j - 1] + p[j]) % modulo
        p = t[:: -1]
        x.append(p[0])
    return LinearRecursion(x, modulo=modulo)[m]

print(T(target_n, target_m))
