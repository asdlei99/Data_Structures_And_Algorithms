#define ClearBiTree DestroyBiTree //������ն����������ٶ������Ĳ�����һ����

//��ʼ��������
void InitBiTree(BiTree &T)  {
    T = NULL;
}

//���������ڣ����ٶ�����
void DestroyBiTree(BiTree &T)  {
    //����������ǿ�
    if (T)  {
        DestroyBiTree(T->lchild);   //����������
        DestroyBiTree(T->rchild);   //����������
        free(T);
        T = NULL;
    }
}

//��������T�ڣ�����ݹ����T�����ζ�ÿ���ڵ����visit()����
void PreOrderTraverse(BiTree T, void(*visit)(TElemType))    {
    if (T)  {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}

//�������������T�����ζ�ÿ��������visit()����
void InOrderTraverse(BiTree T, void(*visit)(TElemType)) {
    if (T)  {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}

//���������ڣ��ж϶������Ƿ�Ϊ��
Status BiTreeEmpty(BiTree T)    {
    if (T)  {
        return FALSE;
    }
    else
    return TRUE;
}

//���������ڣ����ض����������
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

//���������ڣ����ض������ĸ�����ֵ
TElemType Root(BiTree T)    {
    if (BiTreeEmpty(T))
    return Nil;
    else
    return T->data;
}

//���������ڣ�����p��ָ��Ľ���ֵ
TElemType Value(BiTree p)  {
    return p->data;
}

//��p��㸳ֵΪvalue
void Assign(BiTree p, TElemType value)  {
    p->data = value;
}

//�������Ԫ��Ϊ��������ָ������
typedef BiTree QElemType;
#include "c3-2.h"   //����
#include "bo3-2.h"  //���еĻ�������

//���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ��
BiTree Point(BiTree T, TElemType s) {
    LinkQueue q;
    QElemType a;
    //������ǿ�
    if (T)  {
        InitQueue(q);
        EnQueue(q, T);
        //���в�Ϊ��ʱ
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

//������T���ڡ�e��T�е�ĳ���ڵ㣬����e����ֽ����e����ֽ�򷵻�NULL
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

//������T���ڡ�e��T�е�ĳ���ڵ㣬����e���Һ�ֽ����e���Һ�ֽ�򷵻�NULL
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

//������T���ڣ�pָ��T��ĳ��㣬LRΪ0��1.����LRɾ��T��p��ָ�������������������
Status DeleteChild(BiTree p, int LR)    {
    if (p)  {
        //ɾ��������
        if (LR == 0)    {
            ClearBiTree(p->lchild);
        }
        //ɾ��������
        else if (LR == 1) {
            ClearBiTree(p->rchild);
        }
        return OK;
    }
    return ERROR;   //��pΪ�գ�����error
}

//���������ڣ�����ݹ����T����ÿ���ڵ���ú���visit()һ���ҽ�һ��
void PostOrderTraverse(BiTree T, void(*visit)(TElemType))   {
    if (T)  {
        PostOrderTraverse(T->lchild, visit());
        PostOrderTraverse(T->rchild, visit());
        visit(T->data);
    }
}

//�������T����ÿ���ڵ���ú���visit()һ���ҽ�һ�Σ� ���ö���
void LevelOrderTraverse(BiTree T, void(*visit)(TElemType))  {
    LinkQueue q;
    QElemType a;
    if (T)  {
        InitQueue(q);   //��ʼ������
        EnQueue(q, T);  //��ָ�����
        while (!QueueEmpty(q)) {    //���зǿ�
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

//�������������������н���ֵ����Ϊ�ַ��ͻ����ͣ�
void CreateBiTree(BiTree &T)    {
    TElemType ch;
    scanf("from", &ch);
    if (ch == Nil)  {
        T = NULL;
    }
    else {
        T = (BiTree)malloc(sizeof(BiTNode));    //���ɸ��ڵ�
        if (!T) {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//����e��˫��
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
                if (a->lchild)  //a����ֽ
                    EnQueue(q, a->lchild);
                if (a->rchild)  //a���Һ�ֽ
                    EnQueue(q, a->rchild);
            }
        }
    }
    return Nil; //��Ϊ�գ�����eδ�ҵ�
}

//����e�����ֵܣ���e��T����ֽ�������ֵܣ��򷵻ؿ�
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

//����e�����ֵܣ���e��T����ֽ�������ֵܣ��򷵻ؿ�
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

//������T���ڣ�pָ��T��ĳ���ڵ㣬����cΪT��p����������������
Status InsertChild(BiTree p, int LR, BiTree c)  {
    if (p)  {
        //��Ϊ������
        if (LR == 0)    {
            c->rchild = p->lchild;  //pԭ��ָ�����������Ϊc��������
            p->lchild = c;
        }
        //��Ϊ������
        if (LR == 1)    {
            c->rchild = p->rchild;
            p->rchild = c;
        }
    }
    return ERROR;
}

typedef BiTree SElemType;   //����ջԪ��Ϊ��������ָ������
#include "c3-1.h"   //˳��ջ
#include "bo3-1.h"  //˳��ջ�Ļ�������

//���ö�������洢�ṹ�� �������������T�ķǵݹ��㷨����ÿ��Ԫ�ص���visit()����
void InOrderTraverse1(BiTree T, void(*visit)(TElemType))    {
    SqStack S;
    InitStack(S);   //��ʼ��ջ
    while (T || !StackIsEmpty(S)) {
        if (T)  {
            Push(S, T); //��ָ����ջ
            T = T->lchild;
        }
        //��ָ����ջ�����ʸ��ڵ����������
        else {
            Pop(S, T);  //��ս��ָ��
            visit(T->data);
            T = T->rchild;
        }
    }
    printf("\n");
    DestroyStack(S);
}

//���ö�������洢�ṹ�� �������������T�ķǵݹ��㷨����ÿ��Ԫ�ص���visit()����   ��2�ַ���
void InOrderTraverse2(BiTree T, void(*visit)(TElemType))    {
    SqStack S;
    BiTree p;

    InitStack(S);   //��ʼ��ջ
    Push(S, T); //��ָ���ջ(���ۿշ�)
    while (!StackEmpty(S)) {
        //ջ��Ԫ�ز�Ϊ��ָ��
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
