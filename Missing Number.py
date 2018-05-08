#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/08

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
"""


class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # result = set(range(len(nums) + 1))
        # for num in nums:
        #     result.discard(num)
        # return list(result)[0]

        return sum(range(len(nums)+1)) - sum(nums)




if __name__ == '__main__':
    s = Solution()
    nums = [3, 0, 1]
    print(s.missingNumber(nums))

    nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
    print(s.missingNumber(nums))
