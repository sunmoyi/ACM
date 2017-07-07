//
// Created by 孙启龙 on 2016/12/9.
//

struct AvlTree{
    Student Node;
    AvlTree *Lchild, *Rchild;
    int Height;
}*ROOT;

AvlTree* AVLFind(Student St, AvlTree *T)
{
    if (T == NULL)
        return NULL;
    else if (St.num < T->Node.num)
        return AVLFind(St, T->Lchild);
    else if (St.num > T->Node.num)
        return AVLFind(St, T->Rchild);
    return T;
}

AvlTree* FindMax(AvlTree *T)
{
    if(T == NULL)
        return NULL;
    else if (T->Rchild == NULL)
        return T;
    else
        return FindMax(T->Rchild);
}

int Height(AvlTree *T)
{
    if(T == NULL)
        return -1;
    else
        return T->Height;
}

AvlTree *SingleRoteWithLeft(AvlTree *K2)
{
    AvlTree *K1;
    K1 = K2->Lchild;
    K2->Lchild = K1->Rchild;
    K1->Rchild = K2;

    K2->Height = max(Height(K2->Lchild), Height(K2->Rchild)) + 1;
    K1->Height = max(Height(K1->Lchild), Height(K1->Rchild)) + 1;
    return K1;
}

AvlTree* SingRoteWithRight(AvlTree *K2)
{
    AvlTree *K1;

    K1 = K2->Rchild;
    K2->Rchild = K1->Lchild;
    K1->Lchild = K2;

    K2->Height = max(Height(K2->Lchild), Height(K2->Rchild)) + 1;
    K1->Height = max(Height(K1->Lchild), Height(K1->Rchild)) + 1;

    return K1;
}

AvlTree *DoubleRoteWithLeft(AvlTree *K3)
{
    K3->Lchild = SingRoteWithRight(K3->Lchild);

    return SingleRoteWithLeft(K3);
}

AvlTree *DoubleRoteWithRight(AvlTree *K3)
{
    K3->Rchild = SingleRoteWithLeft(K3->Rchild);

    return SingRoteWithRight(K3);
}

AvlTree *Insert(Student X, AvlTree *T)
{
    if(T == NULL)
    {
        T = (AvlTree *)malloc(sizeof(AvlTree));
        T->Node = X;
        T->Height = 0;
        T->Lchild = NULL;
        T->Rchild = NULL;
    }
    else if (X.num < T->Node.num)
    {
        T->Lchild = Insert(X, T->Lchild);
        if(Height(T->Lchild) - Height(T->Rchild) == 2)
        {
            if(X.num < T->Lchild->Node.num)
                T = SingleRoteWithLeft(T);
            else
                T = DoubleRoteWithLeft(T);
        }
    }
    else if (X.num > T->Node.num)
    {
        T->Rchild = Insert(X, T->Rchild);
        if(Height(T->Rchild) - Height(T->Lchild) == 2)
        {
            if(X.num > T->Rchild->Node.num)
                T = SingRoteWithRight(T);
            else
                T = DoubleRoteWithRight(T);
        }
    }

    T->Height = max(Height(T->Lchild), Height(T->Rchild)) + 1;
    return T;
}

void init(AvlTree *T)
{
    if(T != NULL)
    {
        T->Lchild = NULL;
        T->Rchild = NULL;
    }
}

void AVLBuild(Student Stu[], int Size)
{
    ROOT = NULL;
    init(ROOT);
    for (int i = 0; i < Size; i++)
    {
        ROOT = Insert(Stu[i], ROOT);
    }
    printf("AVL-Tree Build!");
}

void AVLsearch(Student St)
{
    if(AVLFind(St, ROOT) != NULL)
        printf("AVL:   Found\n");
    else
        printf("AVL:   Not Found\n");
}













