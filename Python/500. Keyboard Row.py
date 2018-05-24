#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/05/18


Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

https://leetcode.com/static/images/problemset/keyboard.png
American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
"""

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = ['q','w','e','r','t','y','u','i','o','p']
        row2 = ['a','s','d','f','g','h','j','k','l']
        row3 = ['z','x','c','v','b','n','m']
        row1 = set(row1)
        row2 = set(row2)
        row3 = set(row3)
        res = []
        for word in words:
            t = set(word.lower())
            if t & row1 == t or t & row2 == t or t & row3 == t:
                res.append(word)
        return res