#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/16

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
"""


# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        def binarysearch(start,end):
            if guess((end-start)//2+start) == 0:
                return (end-start)//2+start
            elif guess((end-start)//2+start) == -1:
                return binarysearch(start,(end-start)//2+start-1)
            else:
                return binarysearch((end-start)//2+start+1,end)
        return binarysearch(1,n)
