#!/usr/bin/env python3
# -*- coding: utf-8 -*-


n = int(input())
m = int(input())
l = len(bin(m)) - 3
print(int('0b' + bin(m)[-n:], 2) if l >= n else m)
