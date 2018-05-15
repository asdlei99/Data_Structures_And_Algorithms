#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/30

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
"""

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # for i in range(len(nums)):
        #     for j in range(len(nums) - 1):
        #         if nums[i] < nums[j]:
        #             nums[i], nums[j] = nums[j], nums[i]

        i = 0
        j = len(nums) - 1
        k = 0
        while (k <= j):
            if (nums[k] == 0):
                nums[k], nums[i] = nums[i], nums[k]
                i += 1
            elif (nums[k] == 2):
                nums[k], nums[j] = nums[j], nums[k]
                j -= 1
                k -= 1
            k += 1

if __name__ == '__main__':
    s = Solution()
    nums = [2,0,2,1,1,0]
    s.sortColors(nums)
    print(nums)