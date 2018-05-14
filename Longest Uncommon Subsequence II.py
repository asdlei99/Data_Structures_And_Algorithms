#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/14

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
"""


class Solution:
    # def subseq(self, w1, w2):
    #     # Check if w1 is a subsequence of w2

    #     if len(w1) == len(w2):
    #         if w1 == w2:
    #             return True
    #         else:
    #             return False
    #
    #     assert len(w2) > len(w1)
    #     i = 0
    #     for c in w2:
    #         if i < len(w1) and w1[i] == c:
    #             i += 1
    #
    #     return i == len(w1)
    #
    # def findLUSlength(self, strs):
    #     """
    #     :type strs: List[str]
    #     :rtype: int
    #     """
    #
    #     strs.sort(key=len, reverse=True)
    #     for i, w1 in enumerate(strs):
    #         if all(not self.subseq(w1, w2) for j, w2 in enumerate(strs) if i != j and len(w2) >= len(w1)):
    #             return len(w1)
    #
    #     return -1

    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """

        def isSubseq(s1, s2):
            i, m = 0, len(s1)
            for c in s2:
                if i == m: return True
                if s1[i] == c: i += 1
            return i == m

        strs.sort(key=len, reverse=True)
        for i, s1 in enumerate(strs):
            if all(not isSubseq(s1, s2) for j, s2 in enumerate(strs) if i != j):
                return len(s1)
        return -1


if __name__ == '__main__':
    solution = Solution()
    strs = ["aba", "cdc", "eae"]
    print(solution.findLUSlength(strs))

    strs = ["aaa", "aaa", "aa"]
    print(solution.findLUSlength(strs))
