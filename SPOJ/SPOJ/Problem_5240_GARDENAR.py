#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'Yee_172'
__date__ = '2017/12/08'


from math import sqrt


def helen(a, b, c):
    p = (a +b + c) / 2
    return sqrt(p * (p - a) * (p - b) * (p - c))


t = int(input())
for _ in range(t):
    a, b, c = [int(each) for each in input().split(' ')]
    area = sqrt(3) * ((a * a + b * b + c * c) / 4 + sqrt(3) * helen(a, b, c)) / 2
    print('%.2f' % area)
