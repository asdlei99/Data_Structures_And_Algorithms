#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/04/22

Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
"""


class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        index_list = [index for index, value in enumerate(S) if value == C]
        res_list = []
        for s_index in range(len(S)):
            res_list.append(min(abs(index - s_index) for index in index_list))
        return res_list


s = Solution()
S = "loveleetcode"
C = 'e'
print(s.shortestToChar(S, C))
