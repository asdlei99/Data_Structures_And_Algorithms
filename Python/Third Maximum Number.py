#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/05/03

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
"""

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        nums = set(nums)
        if len(nums) < 3: return max(nums)
        a = max(nums)
        nums.remove(a)
        b = max(nums)
        nums.remove(b)
        return max(nums)

        # nums = sorted(list(set(nums)), reverse=True)
        # if len(nums) < 3:
        #     return nums[0]
        # return nums[2]

if __name__ == '__main__':
    s = Solution()
    nums1 = [3, 2, 1]
    nums2 = [1, 2]
    nums3 = [2, 2, 3, 1]
    print(s.thirdMax(nums1))
    print(s.thirdMax(nums2))
    print(s.thirdMax(nums3))