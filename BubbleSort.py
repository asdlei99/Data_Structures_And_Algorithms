#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/13 
"""

def BubbleSort(arr):
    """
    Bubble Sort
    :return:
    """
    # 多少趟
    for i in range(len(arr) - 1):
        # 每趟与多少进行对比
        for j in range(len(arr) - 1 - i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print(arr)

def SelectSort(arr):
    """
    选择排序
    :param arr:
    :return:
    """
    for i in range(len(arr)):
        min = i
        for j in range(i+1, len(arr)):
            if arr[min] > arr[j]:
                arr[min], arr[j] = arr[j], arr[min]
    print(arr)



if __name__ == '__main__':
    arr = [7, 3, 4, 5, 1, 2]
    # BubbleSort(arr)
    # SelectSort(arr)