#define TElemType int
typedef struct BiTNode  {
    TElemType data; //节点的值
    BiTNode *lchild, *rchild; //左右孩纸指针
}BiTNode, *BiTree;
