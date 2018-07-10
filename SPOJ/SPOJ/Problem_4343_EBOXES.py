#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'Yee_172'
__date__ = '2017/12/04'


num = int(input())
for _ in range(num):
    N, K, T, F = [int(each) for each in input().split()]
    print((F - N) // (K - 1) * K + N)
