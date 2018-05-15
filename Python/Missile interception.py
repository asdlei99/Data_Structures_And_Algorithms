#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/22

题目描述
In order to defend against missile attacks, there is a missile interception system. The system has a defect: although its first shot can reach any height, each of the shells can not be higher than the height of the previous one. One day the enemy missiles came in. Since the system is still in the testing stage, it is only possible to intercept all missiles by using one set.

输入
The first line input test data group number N (1<=N<=10)
The next line will input the total number of missile test data m (1<=m<=100).
Next, we input the height of the incoming missiles, and all the heights are all positive integers greater than 0.

输出
The maximum number of missiles that can be intercepted is output, and each group outputs only one line, which contains an integer indicating how many missiles can be intercepted at most.

样例输入
2
5
56 78 34  21  57
7
23 98 45 76 23 75 149
样例输出
3
3
"""

def intercepted(missiles):
    counter = 1
    for i in range(1, len(missiles)):
        if missiles[i] < missiles[i-1]:
            counter += 1
    return counter

print(intercepted([56, 78, 34, 21, 57]))
print(intercepted([23, 98, 45, 76, 23, 75, 149, 1]))