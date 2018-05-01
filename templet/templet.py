#!/usr/bin/env python3
# -*- coding: utf-8 -*-
inf = 0x3f3f3f3f3f3f3f3f
M = mod = 1000000007
mod2inv = 500000004
"""
'''
Timer for testing
'''
import contextlib
import datetime as dt
@contextlib.contextmanager
def timer(s=''):
    start = dt.datetime.now()
    yield
    end = dt.datetime.now()
    if s: print(s + ' : ', end='')
    print(end - start)
usage:
with timer():
    pass

import time 
def cal_time(func):
    def wrapper(*args, **kwargs):
        t1 = time.time()
        result = func(*args, **kwargs)
        t2 = time.time()
        print("running time:",func.__name__, t2 - t1)
        return result
    return wrapper
usage:
@cal_time
pass
"""


'''
from sys import stdin
rl = lambda l: tuple(map(int, l.split()))
array = list(map(rl, stdin.readlines()))
'''


'''
import sys
for line in sys.stdin:
rd = lambda: next(sys.stdin, '').strip()
'''


'''
import sys
sys.setrecursionlimit(10 ** 6)
'''


'''
import sys
if locals()['__file__'][-2:] == 'py':
    sys.stdin = open('in.txt', 'r')
'''


"""
'''
The way to get a series of inverse numbers under module begin with 1
'''
n = 100005
M = 1000000007
inv = [0, 1] + [0] * (n - 1)
for i in range(2, n + 1):
    inv[i] = (mod - mod // i) * inv[mod % i] % mod
"""
'''
Two ways to get single inverse number without generating a table
'''
inv = lambda x: pow(x, M - 2, M)
inv = lambda x: (M - M // x) * inv(M % x) % M if x - 1 else 1



'''
a -> args
k -> kwargs
pt -> print
rd -> read
gcd -> greatest common divisor
'''
pt = lambda *a, **k: print(*a, **k, flush=True)
rd = lambda: map(int, input().split())
gcd = lambda a, b: gcd(b, a % b) if b else a
from math import gcd


'''
fpm -> fast_power_mod
b -> base
e -> exponent
m -> module
r -> result
'''
def fpm(b, e, m):
    r = 1
    while e:
        if e & 1: r = r * b % m
        e >>= 1
        b = b * b % m
    return r
# pow(b, e, m)


'''
gfp -> generate_first_factor
l -> left  -> lower
r -> right -> upper
n -> num
'''
def gff(l, r):
    if r < l: return -1
    if l is 2: return 2
    l = l + 1 if l & 1 is 0 else l
    for n in range(l, r + 1, 2):
        for i in range(3, int(n ** 0.5), 2):
            if n % i is 0: break
        else: return n
    return -1


'''
gf -> generate_factors
gff -> generate_factors_fully
'''
def gf(n):
    d = 2
    while d * d <= n:
        f = 1
        while n % d is 0:
            if f:
                yield d
            f = 0
            n //= d
        d += 1
    if n > 1:
        yield n


def gff(n):
    d = 2
    while d * d <= n:
        while n % d is 0:
            yield d
            n //= d
        d += 1
    if n > 1:
        yield n


'''
ip -> is_prime
'''
def ip(n):
    if n in [2, 3]:
        return 1
    if n % 6 not in [1, 5]:
        return 0
    i = 5
    while i * i <= n:
        if not min(n % i, n % (i + 2)):
            return 0
        i += 6
    return 1


'''
sti -> a linear function to generate stirling numbers of the second kind

Stirling(n, m)
&= \frac{1}{m!} \sum_{k = 0}^{m} (-1)^{k} \binom{m}{k} (m - k)^{n}
&= \sum_{k = 0}^{m} \frac{(-1)^{k} (m - k)^{n}}{(m - k)! k!}

'''
M = 0x3b9aca07
MAXN = 200005
modinv = [0, 1]
for i in range(2, MAXN):
    modinv.append((M - M // i) * modinv[M % i] % M)
fa_inv = [1]
for i in range(1, MAXN):
    fa_inv.append(fa_inv[-1] * modinv[i] % M)
def sti(n, m):
    r = 0
    f = [1, -1]
    if n >= m:
        for i in range(m + 1):
            r = (r + f[i & 1] * fa_inv[m - i] * fa_inv[i] * pow(m - i, n, M)) % M
    return r


'''
npp -> number++
a -> number in array form
'''
number = [0] * 100
def npp(a):
    # if a[-1]: return
    a[0] += 1
    i = 0
    while a[i] > 9:
        a[i] = 0
        i += 1
        a[i] += 1


'''
bs -> binary_search
find the index of the left insertion position of the selected value
'''
def bs(a, v):
    l, r = 0, len(a) - 1
    while l < r:
        m = l + (r - l + 1 >> 1)
        t = a[m]
        if t == v: return m
        elif t < v: l = m
        else r = m - 1
# import bisect
# bi = bisect.insort
# bil = bisect.insort_left
# bir = bisect.insort_right
# bs = bisect.bisect
# bsl = bisect.bisect_left
# bsr = bisect.bisect_right


'''
cb -> change_10base_to_base
   int -> string
ct -> change_base_to_10base # t for ten
   string -> int
CR -> CHARS
n -> num
s -> string
b -> base
'''
CR = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
def cb(n, b):
    return cb(n // b, b) + CR[n % b] if n else ''
def ct(s, b):
    return sum(CR.index(s[i]) * (b ** (len(s) - i - 1)) for i in range(len(s) - 1, -1, -1))


f = lambda c: ord(c) - 97
g = lambda x: chr(97 + x)


class Matrix():
    mod = 0x3b9aca07

    def __init__(self, n):
        self.n = n
        self.a = [[0] * n for _ in range(n)]

    def __mul__(self, b):
        res = Matrix(self.n)
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    res.a[i][j] += self.a[i][k] * b.a[k][j] % Matrix.mod
                    res.a[i][j] %= Matrix.mod
        return res

    def __pow__(self, e):
        res = Matrix(self.n)
        for i in range(self.n):
            res.a[i][i] = 1
        tmp = self
        while e:
            if e & 1:
                res = res * tmp
            e >>= 1
            tmp = tmp * tmp
        return res

    def __str__(self):
        return str(self.a)


class Tree(object):
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.value = 0
        self.left = None
        self.right = None
        if l < r:
            mid = (l + r) // 2
            self.left = Tree(l, mid)
            self.right = Tree(mid + 1, r)
    def set_value(self, p, value):
        if self.l == self.r:
            self.value = value
            return
        mid = (self.l + self.r) // 2
        if p <= mid:
            self.left.set_value(p, value)
        else:
            self.right.set_value(p, value)
        self.push_up()
    def push_up(self):
        self.value = self.left.value + self.right.value
    def query(self, x, y):
        # print ("query", x, y, '\t', (self.l + self.r)/2, '\t', self.l, self.r, self.value)
        if x <= self.l and y >= self.r:
            return self.value
        if self.l == self.r:
            return self.value
        mid = (self.l + self.r) // 2
        if mid >= y:
            return self.left.query(x, y)
        elif mid < x:
            return self.right.query(x, y)
        else:
            return self.left.query(x, mid) + self.right.query(mid + 1, y)


class FenwickTree(object):
    """Implementation of Fenwick Tree (a.k.a Binary Indexed Tree). [v1.0]

    This implentation uses 0-based indexing.
    """
    def __init__(self, n, lst=None):
        """Initialize Fenwick Tree for n elements. If lst is given, Fenwick
        Tree is initiailzed from the list in O(n) time.
        """
        if not lst:
            self._data = [0] * n
        else:
            self._data = lst
            for i in range(1, n + 1):
                j = i + (i & -i)
                if j <= n:
                    self._data[j - 1] += self._data[i - 1]

    def sum(self, beg, end):
        """Return the sum of elements in range [beg, end)."""
        if beg > 0:
            return self.sum(0, end) - self.sum(0, beg)
        s = 0
        while end > 0:
            s += self._data[end - 1]
            end -= end & -end
        return s

    def add(self, idx, val):
        """Add val to the element at idx."""
        idx += 1
        while idx <= len(self._data):
            self._data[idx - 1] += val
            idx += idx & -idx

# https://github.com/leonsim/segmenttree/blob/master/segmenttree/__init__.py
class SegmentTree(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.max_value = {}
        self.sum_value = {}
        self.len_value = {}
        self._init(start, end)

    def add(self, start, end, weight=1):
        start = max(start, self.start)
        end = min(end, self.end)
        self._add(start, end, weight, self.start, self.end)
        return True

    def query_max(self, start, end):
        return self._query_max(start, end, self.start, self.end)

    def query_sum(self, start, end):
        return self._query_sum(start, end, self.start, self.end)

    def query_len(self, start, end):
        return self._query_len(start, end, self.start, self.end)

    """"""
    def _init(self, start, end):
        self.max_value[(start, end)] = 0
        self.sum_value[(start, end)] = 0
        self.len_value[(start, end)] = 0
        if start < end:
            mid = start + int((end - start) / 2)
            self._init(start, mid)
            self._init(mid+1, end)

    def _add(self, start, end, weight, in_start, in_end):
        key = (in_start, in_end)
        if in_start == in_end:
            self.max_value[key] += weight
            self.sum_value[key] += weight
            self.len_value[key] = 1 if self.sum_value[key] > 0 else 0
            return

        mid = in_start + int((in_end - in_start) / 2)
        if mid >= end:
            self._add(start, end, weight, in_start, mid)
        elif mid+1 <= start:
            self._add(start, end, weight, mid+1, in_end)
        else:
            self._add(start, mid, weight, in_start, mid)
            self._add(mid+1, end, weight, mid+1, in_end)
        self.max_value[key] = max(self.max_value[(in_start, mid)], self.max_value[(mid+1, in_end)])
        self.sum_value[key] = self.sum_value[(in_start, mid)] + self.sum_value[(mid+1, in_end)]
        self.len_value[key] = self.len_value[(in_start, mid)] + self.len_value[(mid+1, in_end)]

    def _query_max(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.max_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_max(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_max(start, end, mid+1, in_end)
            else:
                ans = max(self._query_max(start, mid, in_start, mid),
                          self._query_max(mid+1, end, mid+1, in_end))
        #print start, end, in_start, in_end, ans
        return ans

    def _query_sum(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.sum_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_sum(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_sum(start, end, mid+1, in_end)
            else:
                ans = self._query_sum(start, mid, in_start, mid) + self._query_sum(mid+1, end, mid+1, in_end)
        return ans

    def _query_len(self, start, end, in_start, in_end):
        if start == in_start and end == in_end:
            ans = self.len_value[(start, end)]
        else:
            mid = in_start + int((in_end - in_start) / 2)
            if mid >= end:
                ans = self._query_len(start, end, in_start, mid)
            elif mid+1 <= start:
                ans = self._query_len(start, end, mid+1, in_end)
            else:
                ans = self._query_len(start, mid, in_start, mid) + self._query_len(mid+1, end, mid+1, in_end)

        #print start, end, in_start, in_end, ans
        return ans

class SegmentTree():
    """
    zkw segment tree translated by Yee_172 from VinceBlack's magic template
    """
    def __init__(self, n):
        self.d = [0] * (n << 2)
        self.bit = 0

    def build(self, a):
        """
        a : iterator
        """
        self.bit = 1
        while self.bit <= n + 1:
            self.bit <<= 1
        for i in range(self.bit + 1, self.bit + n + 1):
            self.d[i] = next(a)
        for i in range(self.bit - 1, 0, -1):
            self.d[i] = max(self.d[i << 1], self.d[i << 1 | 1])
            self.d[i << 1] -= self.d[i]
            self.d[i << 1 | 1] -= self.d[i]

    def update(self, l, r, val):
        l += self.bit
        r += self.bit
        if (l == r):
            self.d[l] += val
            while l > 1:
                temp = max(self.d[l], self.d[l ^ 1])
                self.d[l] -= temp
                self.d[l ^ 1] -= temp
                self.d[l >> 1] += temp
                l >>= 1
            return
        self.d[l] += val
        self.d[r] += val
        while l ^ r ^ 1:
            if ~ s & 1:
                self.d[l ^ 1] += val
            if t & 1:
                self.d[r ^ 1] += val
            temp = max(self.d[l], self.d[l^1])
            self.d[l] -= temp
            self.d[l ^ 1] -= temp
            self.d[l >> 1] += temp
            temp = max(self.d[r], self.d[r^1])
            self.d[r] -= temp
            self.d[r ^ 1] -= temp
            self.d[r >> 1] += temp
            l >>= 1
            r >>= 1
        while l > 1:
            temp = max(self.d[l], self.d[l ^ 1])
            self.d[l] -= temp
            self.d[l ^ 1] -= temp
            self.d[l >> 1] += temp

    def query(self, l, r):
        lans = 0
        rans = 0
        if l == r:
            l += self.bit
            while l:
                lans += self.d[l]
                l >>= 1
            return lans
        l += self.bit
        r += self.bit
        while l ^ r ^ 1:
            lans += self.d[l]
            rans += self.d[r]
            if ~ l & 1:
                lans = max(lans, self.d[l ^ 1])
            if r & 1:
                rans = max(rans, self.d[r ^ 1])
            l >>= 1
            r >>= 1
        lans += self.d[l]
        rans += self.d[r]
        ans = max(lans, rans)
        while l > 1:
            l >>= 1
            ans += self.d[l]
        return ans

class vector:
    def __init__(self, _x = 0, _y = 0):
        self.x = _x
        self.y = _y
    def len(self):
        return sqrt(self.x ** 2 + self.y ** 2)
    def len_sq(self):
        return self.x ** 2 + self.y ** 2
    def __mul__(self, other):
        if (type(self) == type(other)):
            return self.x * other.x + self.y * other.y
        return vector(self.x * other, self.y * other)
    def __mod__(self, other):
        return self.x * other.y - self.y * other.x
    def normed(self):
        length = self.len()
        return vector(self.x / length, self.y / length)
    def normate(self):
        self = self.normed()
    def __str__(self):
        return "(" + str(self.x) + ", " + str(self.y) + ")"
    def __add__(self, other):
        return vector(self.x + other.x, self.y + other.y);
    def __sub__(self, other):
        return vector(self.x - other.x, self.y - other.y);
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    def rot(self):
        return vector(self.y, -self.x)

class line:
    def __init__(self, a = 0, b = 0, c = 0):
        self.a = a
        self.b = b
        self.c = c
    def intersect(self, other):
        d = self.a * other.b - self.b * other.a
        dx = self.c * other.b - self.b * other.c
        dy = self.a * other.c - self.c * other.a
        return vector(dx / d, dy / d)
    def fake(self, other):
        d = self.a * other.b - self.b * other.a
        return d
    def __str__(self):
        return str(self.a) + "*x + " + str(self.b) + "*y = " + str(self.c)

def line_pt(A, B):
    d = (A - B).rot()
    return line(d.x, d.y, d * A)

class circle:
    def __init__(self, O = vector(0, 0), r = 0):
        self.O = O
        self.r = r
    def intersect(self, other):
        O1 = self.O
        O2 = other.O
        r1 = self.r
        r2 = other.r
        if (O1 == O2):
            return []
        if ((O1 - O2).len_sq() > r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
            return []
        rad_line = line(2 * (O2.x - O1.x), 2 * (O2.y - O1.y), r1 ** 2 - O1.len_sq() - r2 ** 2 + O2.len_sq())
        central = line_pt(O1, O2)
        M = rad_line.intersect(central)
        # print(M)
        if ((O1 - O2).len_sq() == r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
            return [M]
        d = (O2 - O1).normed().rot()
        if (r1 ** 2 - (O1 - M).len_sq() < 0):
            return []
        d = d * (sqrt(r1 ** 2 - (O1 - M).len_sq()))
        return [M + d, M - d]
    def fake(self, other):
        O1 = self.O
        O2 = other.O
        r1 = self.r
        r2 = other.r
        if (O1 == O2):
            return 1
        if ((O1 - O2).len_sq() > r1 ** 2 + r2 ** 2 + 2 * r1 * r2):
            return 1
        rad_line = line(2 * (O2.x - O1.x), 2 * (O2.y - O1.y), r1 ** 2 - O1.len_sq() - r2 ** 2 + O2.len_sq())
        central = line_pt(O1, O2)
        return rad_line.fake(central)

class DSet:
    def __init__(self, n):
        self.parents = [-1 for i in range(n)]
        self.rank = [0 for i in range(n)]

    def find(self, n):
        if self.parents[n] is -1:
            return n
        ret = self.find(self.parents[n])
        self.parents[n] = ret
        return ret

    def union(self, a, b):
        if a is -1 or b is -1:
            return False
        x, y = self.find(a), self.find(b)
        if self.find(a) == self.find(b) and x is not -1:
            return False
        if self.rank[x] == self.rank[y]:
            self.parents[x] = y
            self.rank[x] = self.rank[y] = self.rank[x] + 1
        elif self.rank[x] > self.rank[y]:
            self.parents[y] = x
            self.rank[y] = self.rank[x]
        else:
            self.parents[x] = y
            self.rank[x] = self.rank[y]
        return True

uf = [i for i in range(len(s))]

def find(uf,i):
    p = uf[i]
    return p if i==p else find(uf,p)

def union(uf,i,j):
    uf[find(uf,i)] = find(uf,j)
