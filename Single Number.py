#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/27

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 超时
        # for num in nums:
        #     if nums.count(num) == 1:
        #         return num
        # return None

        return sum(list(set(nums))) * 2 - sum(nums)

if __name__ == '__main__':
    s = Solution()
    nums = [4,1,2,1,2]
    print(s.singleNumber(nums))