#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/04

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
"""


class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        # import numpy as np
        # try:
        #     return np.array(nums).reshape(r, c).tolist()
        # except ValueError:
        #     return np.array(nums).tolist()

        new_list = []
        new_nums = []
        for num in nums:
            new_list += num
        if len(new_list) != r * c:
            return nums
        for i in range(0, r):
            new_nums.append(new_list[i*c : (i+1)*c])
        return new_nums

if __name__ == '__main__':
    s = Solution()

    nums =[[1, 2], [3, 4]]
    r = 2
    c = 4
    nums = s.matrixReshape(nums, r, c)
    print(nums)

    nums =[[1, 2], [3, 4]]
    r = 1
    c = 4
    nums = s.matrixReshape(nums, r, c)
    print(nums)