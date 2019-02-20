# Let T(n, m) be the number of m-tuples of positive
# integers such that the sum of any two neighbouring
# elements of the tuple is \leq n.
# Find T(5000, 1e12) mod 1000000007.
# ----------------------------------------------------
# Analysis: Let D(t, m) be the number of m-tuples of positive integers start with t, we get
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

MOD = 0x3b9aca07

def Berlekamp_Massey_Algorithm(x, **kwargs):
    modulo = kwargs.get('modulo', 0)
    recursion = []
    last_fail_state = []
    for i in range(len(x)):
        expectation_delta = -x[i]
        if modulo:
            expectation_delta %= modulo
        for j, r in enumerate(recursion):
            expectation_delta += x[i - j - 1] * r
            if modulo:
                expectation_delta %= modulo
        if -1e-8 < expectation_delta < 1e-8:
            continue
        if not len(recursion):
            recursion = [0] * (i + 1)
            fail = i
            delta = expectation_delta
            continue
        if modulo:
            multiple = -expectation_delta * pow(delta, modulo - 2, modulo) % modulo
        else:
            multiple = -expectation_delta / delta
        change = [0] * (i - fail - 1) + [-multiple]
        for r in last_fail_state:
            addition = r * multiple
            if modulo:
                addition %= modulo
            change.append(addition)
        if len(change) < len(recursion):
            change += [0] * (len(recursion) - len(change))
        for j, r in enumerate(recursion):
            change[j] += r
            if modulo:
                change[j] %= modulo
        if i - fail + len(last_fail_state) >= len(recursion):
            last_fail_state = recursion
            fail = i
            delta = expectation_delta
        recursion = change
    return recursion

R = []

class Polynomial:
    def __init__(self, p):
        self.p = p
        self.n = len(p)

    def __mul__(self, b):
        r = [0] * (self.n + b.n - 1)
        for i, x in enumerate(self.p):
            if x:
                for j, y in enumerate(b.p):
                    r[i + j] += x * y
                    r[i + j] %= MOD
        for i in range(self.n + b.n - 2, self.n - 1, -1):
            if r[i]:
                for j in range(self.n - 1, -1, -1):
                    r[i - j - 1] += r[i] * R[j]
                    r[i - j - 1] %= MOD
        return Polynomial(r[: self.n])

    def __str__(self):
        return str(self.p)

def get_res(n, e):
    r, t = [0] * n, [0] * n
    r[0] = 1
    if n == 1:
        t[0] = R[0]
    else:
        t[1] = 1
    r, t = Polynomial(r), Polynomial(t)
    while e:
        if e & 1:
            r *= t
        t *= t
        e >>= 1
    return r.p

def T(n, m):
    global R
    p = [1] * (n - 1)
    if m < n << 1:
        for i in range(m):
            t = [0] * (n - 1)
            for j in range(n - 1):
                t[j] = (t[j - 1] + p[j]) % MOD
            p = t[:: -1]
        return p[0]
    x = [1]
    for i in range(n << 1):
        t = [0] * (n - 1)
        for j in range(n - 1):
            t[j] = (t[j - 1] + p[j]) % MOD
        p = t[:: -1]
        x.append(p[0])
    R = Berlekamp_Massey_Algorithm(x, modulo=MOD)
    r = get_res(len(R), m)
    return sum(map(lambda i: r[i] * x[i] % MOD, range(len(R)))) % MOD

print(T(5000, 10 ** 12))
