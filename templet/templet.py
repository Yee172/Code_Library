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
