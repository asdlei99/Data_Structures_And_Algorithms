#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/01

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

"""


class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        # l = len(matrix)
        # for i in range(l - 1):
        #     for j in range(i, l - i - 1):
        #         matrix[i][j], matrix[j][l - 1 - i], matrix[l - 1 - i][l - 1 - j], matrix[l - 1 - j][i] = \
        #             matrix[l - 1 - j][i], matrix[i][j], matrix[j][l - 1 - i], matrix[l - 1 - i][l - 1 - j]

        # import numpy as np
        # matrix = np.transpose(matrix)
        # for i in range(len(matrix)):
        #     lens = len(matrix[0])
        #     for j in range(int(lens / 2)):
        #         tmp = matrix[i][j]
        #         matrix[i][j] = matrix[i][lens - j - 1]
        #         matrix[i][lens - j - 1] = tmp
        # print(matrix)
        matrix[::] = zip(*matrix[::-1])

if __name__ == '__main__':
    s = Solution()
    matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    matrix2 = [
        [5, 1, 9, 11],
        [2, 4, 8, 10],
        [13, 3, 6, 7],
        [15, 14, 12, 16]
    ]

    s.rotate(matrix1)
    s.rotate(matrix2)

    print(matrix1)
    print('---------------')
    print(matrix2)
