#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/13


Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
"""


class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for ii in range(-10, target + 1):
            if ii in numbers and target - ii in numbers:
                return numbers.index(ii) + 1, numbers[numbers.index(ii) + 1:].index(
                    target - ii) + 1 + numbers.index(ii) + 1


if __name__ == '__main__':
    solution = Solution()

    numbers = [2, 7, 11, 15]
    target = 9
    print(solution.twoSum(numbers, target))
