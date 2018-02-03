#!/usr/bin/env python3
# -*- coding: utf-8 -*-


read = lambda: map(int, input().split())


def fast_exp_mod(base, exponent, module):
    result = 1
    while exponent != 0:
        if (exponent & 1) is 1:
            result = (result * base) % module
        exponent >>= 1
        base = (base * base) % module
    return result


def generate_first_prime(lower, upper):
    if upper < lower:
        return -1
    if lower is 2:
        return 2
    lower = lower + 1 if lower & 1 is 0 else lower
    for num in range(lower, upper + 1, 2):
        for i in range(2, num):
            if (num % i) is 0:
                break
        else:
            return num
    return -1


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
