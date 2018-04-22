#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/22 
"""

m = 6
n = 10

letters = 'ABCDEFGHIJKLMOPQRSTUVWXYZ'
str = letters[:n]

for i in range(m):
    print(str[::-1][n-1:-1], end='')
    print(str[:n])
    n -= 1
