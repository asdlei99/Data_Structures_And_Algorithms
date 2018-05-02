#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/05/02

Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?

"""


class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        # return int('{:032b}'.format(n)[::-1], 2)
        # zfill padding 0 to left.
        return int(bin(n)[2:].zfill(32)[::-1], 2)

if __name__ == '__main__':
    s = Solution()
    print(s.reverseBits(43261596))