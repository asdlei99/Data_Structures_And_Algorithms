#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/04/13 
"""


# ------------单向链表------------
class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


L = Node('a', Node('b', Node('c', Node('d'))))
print(L.next.next.value)

squared = [x**2 for x in range(5)]

squared2 = map(lambda x: x **2, [x for x in range(5)])
print([x for x in squared2])