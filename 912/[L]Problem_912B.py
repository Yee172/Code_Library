#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#__author__ = 'Yee_172'
__date__ = '2018/01/06'


# n,k=map(int,input().split())
# print(n if k==1 else (1<<len(bin(n))-2)-1)


n,k=map(int,input().split())
print(n if k==1 else int(bin(n)[2:].replace('0','1'),2))
