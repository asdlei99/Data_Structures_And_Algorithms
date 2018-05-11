#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/05/11


Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
"""

class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        try:
            return len(s.split()[-1])
        except:
            return 0

if __name__ == '__main__':
    solution = Solution()
    s = " "
    print(solution.lengthOfLastWord(s))