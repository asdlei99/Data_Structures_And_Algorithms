#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/05/12

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

"""

class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        # for r in ransomNote:
        #     if r not in magazine:
        #         return False
        #     else:
        #         magazine = magazine.replace(r, '', 1)
        # return True

        ransom = set(ransomNote)
        for i in ransom:
            if ransomNote.count(i) > magazine.count(i):
                return False
        return True

if __name__ == '__main__':
    solution = Solution()
    ransomNote = "a"
    magazine = "b"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "aa"
    magazine = "ab"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "aa"
    magazine = "aab"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "bg"
    magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
    print(solution.canConstruct(ransomNote, magazine))