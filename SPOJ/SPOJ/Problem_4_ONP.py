#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'Yee_172'
__date__ = '2017/12/02'


t = int(input())
for _ in range(t):
    letter = []
    operation = []
    info = input()
    for each in info:
        if each.isalpha():
            letter.append(each)
        elif each is ')':
            temp = letter[-2] + letter[-1] + operation[-1]
            letter.pop()
            letter.pop()
            operation.pop()
            operation.pop()
            letter.append(temp)
        else:
            operation.append(each)
    print(letter[0])
