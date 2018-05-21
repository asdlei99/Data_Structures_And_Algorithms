#define ClearBiTree DestroyBiTree //定义清空二叉树和销毁二叉树的操作是一样的

//初始化二叉树
void InitBiTree(BiTree &T)  {
    T = NULL;
}

//二叉树存在，销毁二叉树
void DestroyBiTree(BiTree &T)  {
    //如果二叉树非空
    if (T)  {
        DestroyBiTree(T->lchild);   //销毁左子树
        DestroyBiTree(T->rchild);   //销毁右子树
        free(T);
        T = NULL;
    }
}

//二叉树存T在，先序递归遍历T，依次对每个节点调用visit()函数
void PreOrderTraverse(BiTree T, void(*visit)(TElemType))    {
    if (T)  {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}

//中序遍历二叉树T，依次对每个结点调用visit()函数
void InOrderTraverse(BiTree T, void(*visit)(TElemType)) {
    if (T)  {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}

//二叉树存在，判断二叉树是否为空
Status BiTreeEmpty(BiTree T)    {
    if (T)  {
        return FALSE;
    }
    else
    return TRUE;
}

//二叉树存在，返回二叉树的深度
int BiTreeDepth(BiTree T)   {
    int i, j;
    if (!T) {
        return 0;
    }
    else    {
        i = BiTreeDepth(T->lchild);
        j = BiTreeDepth(T->rchild);
        return i > j ? i + 1 : j + 1;
    }
}

//二叉树存在，返回二叉树的根结点的值
TElemType Root(BiTree T)    {
    if (BiTreeEmpty(T))
    return Nil;
    else
    return T->data;
}

//二叉树存在，返回p所指向的结点的值
TElemType Value(BiTree p)  {
    return p->data;
}

//给p结点赋值为value
void Assign(BiTree p, TElemType value)  {
    p->data = value;
}

//定义队列元素为二叉树的指针类型
typedef BiTree QElemType;
#include "c3-2.h"   //队列
#include "bo3-2.h"  //队列的基本操作

//返回二叉树T中指向元素值为s的结点的指针
BiTree Point(BiTree T, TElemType s) {
    LinkQueue q;
    QElemType a;
    //如果树非空
    if (T)  {
        InitQueue(q);
        EnQueue(q, T);
        //队列不为空时
        while (!QueueEmpty(q))  {
            DeQueue(q, a);
            if (a->data == s)   {
                DestroyQueue(q);
                return a;
            }
            if (a->lchild)  {
                EnQueue(q, a->lchild);
            }
            if (a->rchild)  {
                EnQueue(q, a->rchild);
            }
            DestroyQueue(q);
        }
    }
    return NULL;
}

//二叉树T存在。e是T中的某个节点，返回e的左孩纸，若e无左孩纸则返回NULL
TElemType LeftChild(BiTree T, TElemType e)  {
    BiTree a;
    if (T)  {
        a = Point(T, e);
        if (a && a->lchild) {
            return a->lchild->data;
        }
    }
    return Nil;
}

//二叉树T存在。e是T中的某个节点，返回e的右孩纸，若e无右孩纸则返回NULL
TElemType RightChild(BiTree T, TElemType e)  {
    BiTree a;
    if (T)  {
        a = Point(T, e);
        if (a && a->rchild) {
            return a->rchild->data;
        }
    }
    return Nil;
}

//二叉树T存在，p指向T中某结点，LR为0或1.根据LR删除T中p所指向结点的左子树或右子树
Status DeleteChild(BiTree p, int LR)    {
    if (p)  {
        //删除左子树
        if (LR == 0)    {
            ClearBiTree(p->lchild);
        }
        //删除右子树
        else if (LR == 1) {
            ClearBiTree(p->rchild);
        }
        return OK;
    }
    return ERROR;   //数p为空，返回error
}

//二叉树存在，后序递归遍历T，对每个节点调用函数visit()一次且仅一次
void PostOrderTraverse(BiTree T, void(*visit)(TElemType))   {
    if (T)  {
        PostOrderTraverse(T->lchild, visit());
        PostOrderTraverse(T->rchild, visit());
        visit(T->data);
    }
}

//层序遍历T，对每个节点调用函数visit()一次且仅一次， 利用队列
void LevelOrderTraverse(BiTree T, void(*visit)(TElemType))  {
    LinkQueue q;
    QElemType a;
    if (T)  {
        InitQueue(q);   //初始化队列
        EnQueue(q, T);  //根指针入队
        while (!QueueEmpty(q)) {    //队列非空
            DeQueue(q, a);
            visit(a->data);
            if (a->lchild)  {
                EnQueue(q, a->lchild);
            }
            if (a->rchild)  {
                EnQueue(q, a->rchild);
            }
        }
        printf("\n");
        DestroyQueue(q);
    }
}

//按先序次序输入二叉树中结点的值（可为字符型或整型）
void CreateBiTree(BiTree &T)    {
    TElemType ch;
    scanf("from", &ch);
    if (ch == Nil)  {
        T = NULL;
    }
    else {
        T = (BiTree)malloc(sizeof(BiTNode));    //生成根节点
        if (!T) {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//返回e的双亲
TElemType Parent(BiTree T, TElemType e) {
    LinkQueue q;
    QElemType a;
    if (T)  {
        InitQueue(q);
        EnQueue(q, T);
        while (!QueueEmpty(q)) {
            DeQueue(q, a);
            if (a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e) {
                return a->data;
            }
            else {
                if (a->lchild)  //a有左孩纸
                    EnQueue(q, a->lchild);
                if (a->rchild)  //a有右孩纸
                    EnQueue(q, a->rchild);
            }
        }
    }
    return Nil; //树为空，或者e未找到
}

//返回e的左兄弟，若e是T的左孩纸或无左兄弟，则返回空
TElemType LeftSibling(BiTree T, TElemType e)    {
    TElemType a;
    BiTree p;
    if (T)  {
        a = Parent(T, e);
        if (a != Nil) {
            p = Point(T, a);
            if (p->lchild && p->rchild && p->rchild->data == e)  {
                return p->lchild->data;
            }
        }
    }
    return Nil;
}

//返回e的右兄弟，若e是T的左孩纸或无右兄弟，则返回空
TElemType RightSibling(BiTree T, TElemType e)    {
    TElemType a;
    BiTree p;
    if (T)  {
        a = Parent(T, e);
        if (a != Nil) {
            p = Point(T, a);
            if (p->lchild && p->rchild && p->lchild->data == e)  {
                return p->lchild->data;
            }
        }
    }
    return Nil;
}

//二叉树T存在，p指向T的某个节点，插入c为T中p的左子树或右子树
Status InsertChild(BiTree p, int LR, BiTree c)  {
    if (p)  {
        //插为左子树
        if (LR == 0)    {
            c->rchild = p->lchild;  //p原来指向的左子树成为c的右子树
            p->lchild = c;
        }
        //插为右子树
        if (LR == 1)    {
            c->rchild = p->rchild;
            p->rchild = c;
        }
    }
    return ERROR;
}

typedef BiTree SElemType;   //定义栈元素为二叉树的指针类型
#include "c3-1.h"   //顺序栈
#include "bo3-1.h"  //顺序栈的基本操作

//采用二叉链表存储结构， 中序遍历二叉树T的非递归算法，对每个元素调用visit()函数
void InOrderTraverse1(BiTree T, void(*visit)(TElemType))    {
    SqStack S;
    InitStack(S);   //初始化栈
    while (T || !StackIsEmpty(S)) {
        if (T)  {
            Push(S, T); //根指针入栈
            T = T->lchild;
        }
        //根指针退栈，访问根节点遍历右子树
        else {
            Pop(S, T);  //出战根指针
            visit(T->data);
            T = T->rchild;
        }
    }
    printf("\n");
    DestroyStack(S);
}

//采用二叉链表存储结构， 中序遍历二叉树T的非递归算法，对每个元素调用visit()函数   第2种方法
void InOrderTraverse2(BiTree T, void(*visit)(TElemType))    {
    SqStack S;
    BiTree p;

    InitStack(S);   //初始化栈
    Push(S, T); //根指针进栈(无论空否)
    while (!StackEmpty(S)) {
        //栈顶元素不为空指针
        while (GetTop(S, p) && p)   {
            Push(S, p->lchild);
        }
        Pop(S, T);
        if (!StackEmpty(S)) {
            Pop(S, p);
            visit(p->data);
            Push(S, p->rchild);
        }
    }
    printf("\n");
    DestroyStack(S);
}
