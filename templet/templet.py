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
"""


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


'''
gfp -> generate_first_prime
l -> left  -> lower
r -> right -> upper
n -> num
'''
def gfp(l, r):
    if r < l: return -1
    if l is 2: return 2
    l = l + 1 if l & 1 is 0 else l
    for n in range(l, r + 1, 2):
        for i in range(3, n, 2):
            if n % i is 0: break
        else: return n
    return -1


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
