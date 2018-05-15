#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/22 
"""
def check(str):
    stack = []
    for s in str:
        if s in ['(', '[', '{']:
            stack.append(s)
        else:
            if match(s) != stack[-1]:
                return 'No'
            else:
                stack.pop(-1)
    if len(stack) == 0:
        return 'Yes'

def match(s):
    if s == ')':
        return '('
    if s == ']':
        return '['
    if s == '}':
        return '{'



print(check('[(][])'))
print(check('[((]))'))
print(check('[([[]()])]'))