#!usr/bin/env python  
#-*- coding:utf-8 -*- 

""" 
@author:yzk13 
@time: 2018/04/24 
二叉树
"""

class Node:
    """
    节点类
    """
    def __init__(self, value):
        self.value = value
        # 左孩子
        self.lchild = None
        # 右孩子
        self.rchild = None

class Tree:
    def __init__(self):
        """
        初始化
        """
        self.root = None

    def add(self, value):
        """
        添加节点
        :param value:
        :return:
        """
        node = Node(value)
        if self.root is None:
            self.root = node
        else:
            q = [self.root]
            while True:
                pop_node = q.pop(0)
                if pop_node.lchild is None:
                    pop_node.lchild = node
                    return
                elif pop_node.rchild is None:
                    pop_node.rchild = node
                    return
                else:
                    q.append(pop_node.lchild)
                    q.append(pop_node.rchild)

    def traverse(self):
        """
        层序遍历
        :return:
        """
        if self.root == None:
            print('Nothing')
        else:
            q = [self.root]
            result = [self.root.value]
            while q != []:
                pop_node = q.pop(0)
                if pop_node.lchild != None:
                    q.append(pop_node.lchild)
                    result.append(pop_node.lchild.value)
                if pop_node.rchild != None:
                    q.append(pop_node.rchild)
                    result.append(pop_node.rchild.value)
            return result

    def preorder(self, root):
        """
        先序遍历
        :param root:
        :return:
        """
        if root == None:
            return []
        else:
            result = [root.value]
            left_values = self.preorder(root.lchild)
            right_values = self.preorder(root.rchild)
            return result + left_values + right_values

    def inorder(self, root):
        """
        中序遍历
        :param root: 
        :return: 
        """
        if root == None:
            return []
        else:
            result = [root.value]
            left_values = self.inorder(root.lchild)
            right_values = self.inorder(root.rchild)
            return left_values + result + right_values

    def postorder(self, root):
        """
        后序遍历
        :param root:
        :return:
        """
        if root == None:
            return []
        else:
            result = [root.value]
            left_values = self.postorder(root.lchild)
            right_values = self.postorder(root.rchild)
            return left_values + right_values + result

if __name__ == '__main__':
    t = Tree()
    for i in range(10):
        t.add(i)

    print('层次遍历: ', t.traverse())
    print('先序遍历: ', t.preorder(t.root))
    print('中序遍历: ', t.inorder(t.root))
    print('后序遍历: ', t.postorder(t.root))
