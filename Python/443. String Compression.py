#!usr/bin/env python  
# -*- coding:utf-8 -*-

""" 
@author:yzk13 
@time: 2018/05/22

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

"""


class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        length = len(chars)

        if length < 2:
            return 1

        p2 = 1
        p1 = 0

        count = 1

        while p2 < length:
            mc = 1

            while p2 < length and chars[p1] == chars[p2]:
                p2 += 1
                mc += 1

            if mc > 1:
                string = str(mc)

                for i in string:
                    count += 1
                    p1 += 1
                    chars[p1] = i

            p1 += 1
            if p2 < length:
                chars[p1] = chars[p2]
                count += 1
            p2 += 1

        return count


if __name__ == '__main__':
    solution = Solution()
    chars = ["a", "a", "b", "b", "c", "c", "c"]
    print(solution.compress(chars))
