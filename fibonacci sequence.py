#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/22

题目描述
Infinite sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55... Called Fibonacci sequence, which can be recursively defined as

F (n) =1... (n=1 or n=2)

F (n) =F (n-1) +F (n-2)... (n>2)

We want you to find the first n Fibonacci numbers. (first, second are 1)

输入
The first line is an integer m (m<5) which represents the common M group test data.

There is only one row per test data, and there is only one shaping number n (n<20).

输出
 for each group Input n  and output the number of n Fibonacci
"""

def fib(n):
    if  n == 1 or n == 2:
        return 1
    else:
        return fib(n-2) + fib(n-1)

l = int(input())
r = []
for i in range(l):
    r.append(int(input()))

for i in r:
    print(fib(i))

