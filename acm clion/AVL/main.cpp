#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
AvlTree MakeEmpty(AvlTree T);
AvlTree Find(ElementType X, AvlTree T);
AvlTree FindMin(AvlTree T);
AvlTree FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
Position SingleRoteWithLeft(Position K2);
Position doubleRoteWithLeft(Position K3);
Position SingleRoteWithRight(Position K2);
Position doubleRoteWithRight(Position K3);
AvlTree init(AvlTree T);
int Height(Position P);
void print(AvlTree T);

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Hight;
};

AvlTree MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

AvlTree Find(ElementType X, AvlTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    return T;
}

AvlTree FindMin(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

AvlTree FindMax(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Hight;
}

Position SingleRoteWithLeft(Position K2)
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Hight = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Hight = max(Height(K1->Left), Height(K2->Right)) + 1;
    return K1;
}

Position doubleRoteWithLeft(Position K3)
{
    K3->Left = SingleRoteWithRight(K3->Left);

    return SingleRoteWithLeft(K3);
}

Position SingleRoteWithRight(Position K2)
{
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Hight = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Hight = max(Height(K1->Right), Height(K2->Left)) + 1;
    return K1;
}

Position doubleRoteWithRight(Position K3)
{
    K3->Right = SingleRoteWithLeft(K3->Right);

    return SingleRoteWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        T = (AvlNode *)malloc(sizeof(AvlNode));
        if (T == NULL)
            cout << "out of space!" << endl;
        else
        {
            T->Element = X; T->Hight = 0;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->Element)
                T = SingleRoteWithLeft(T);
            else
                T = doubleRoteWithLeft(T);
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->Element)
                T = SingleRoteWithRight(T);
            else
                T = doubleRoteWithRight(T);
        }
    }

    T->Hight = max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
    Position TempCall;

    if (T == NULL)
        cout << "Element not found" << endl;
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right)
    {
        TempCall = FindMin(T->Right);
        T->Element = TempCall->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else
    {
        TempCall = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TempCall);
    }
    return T;
}

AvlTree init(AvlTree T)
{
    if (T != NULL)
    {
        T->Left = NULL;
        T->Right = NULL;
        T->Element = -1;
    }
    return T;
}

void print(AvlTree T)
{
    if (T->Left != NULL)
        print(T->Left);
    printf("%d\n", T->Element);
    if (T->Right != NULL)
        print(T->Right);
}

int main(void)
{
    AvlTree T = NULL;
    init(T);
    int m, n, temp;
    printf("please input number");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        T = Insert(temp, T);
    }
    printf("plase input Find keys\n");
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &temp);
        AvlTree A = Find(temp, T);
        if(A == NULL)
            printf("not Found\n");
        else
            printf("Found\n");
    }

    return 0;
}
