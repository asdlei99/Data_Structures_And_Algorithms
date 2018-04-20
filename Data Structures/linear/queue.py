#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/20
队列
"""

class Queue(object):
    """
    队列
    """
    def __init__(self, size):
        """
        初始化
        """
        self.size = size
        self.queue = []

    @property
    def length(self):
        """
        获取队列长度
        :return:
        """
        return len(self.queue)

    def isfull(self):
        """
        判断队列是否已满
        :return:
        """
        return self.size == len(self.queue)

    def enqueue(self, item):
        """
        入队, 队满报错，否则将被插到队尾
        :param item:
        :return:
        """
        if self.isfull():
            print('队满')
        else:
            self.queue.append(item)

    def dequeue(self):
        """
        出队, 队空报错，否则队头元素出队
        :return:
        """
        if self.is_empty():
            print('队空')
        else:
            # firstElement = self.queue[0]
            # self.queue.remove(firstElement)
            # return firstElement
            return self.queue.pop(0)

    def is_empty(self):
        """
        队是否为空
        :return:
        """
        return self.length == 0

    def print(self):
        """
        打印
        :return:
        """
        print(self.queue)

    def sort(self):
        """
        排序
        :return:
        """
        self.queue.sort()


if __name__ == '__main__':
    q = Queue(5)

    # 入队
    q.enqueue(3)
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(6)
    q.print()

    # 出队
    q.dequeue()
    print('出队后: ', end='')
    q.print()

    # 排序
    q.sort()
    print('排序后: ', end='')
    q.print()

    # 测试队满
    q.enqueue(3)
    q.enqueue(5)
    print('当前队长: ', q.length)
    q.enqueue(5)