#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'Yee_172'
__date__ = '2017/12/04'


from math import pi


l = int(input())
while l:
    print('%.2f' %(l * l / 2 / pi))
    l = int(input())
