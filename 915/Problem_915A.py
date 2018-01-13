#!/usr/bin/env python3
# -*- coding: utf-8 -*-


n, k = [int(_) for _ in input().split(' ')]
m = 100
a = [int(__) for __ in input().split(' ')]
for _ in range(n):
    if k % a[_] is 0 and k // a[_] < m:
        m = k // a[_]
print(m)
