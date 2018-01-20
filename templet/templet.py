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

