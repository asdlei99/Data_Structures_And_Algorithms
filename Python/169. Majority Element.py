#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/16

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
"""


class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tmp = list(set(nums))
        for i in tmp:
            if nums.count(i) > (len(nums) / 2):
                return i


if __name__ == '__main__':
    solution = Solution()
    nums = [2, 2, 1, 1, 1, 2, 2]
    print(solution.majorityElement(nums))
