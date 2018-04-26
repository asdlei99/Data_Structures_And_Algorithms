#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/26

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
"""

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]

if __name__ == '__main__':
    s = Solution()
    print(s.reverseString('hello'))