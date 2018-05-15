#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/20

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
"""

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        return int(x ** 0.5)

        # if x == 0:
        #     return 0
        # if x == 0:
        #     return 0
        # low = 1
        # high = x
        # mark = 1
        # while low != high - 1:
        #     mid = (high + low) / 2
        #     if mid * mid > x:
        #         high = mid
        #     elif mid * mid < x:
        #         mark = mid
        #         low = mid
        #     else:
        #         return mid
        # return mark

s = Solution()
print(s.mySqrt(8))