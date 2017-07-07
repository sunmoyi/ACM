#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;
typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p, List L);
Position Find(ElementType x, List L);
void Delete(ElementType x, List L);
Position FindPrevious(ElementType x, List L);
void Insert(ElementType x, List L, Position p);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
ElementType Retrive(Position P);

struct Node{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position p, List L)
{
    return p->Next == NULL;
}

Position Find(ElementType x, List L)
{
    Position  P;

    P = L->Next;
    while(P != NULL && P->Element != x)
        P = P->Next;

    return P;
}

void Delete(ElementType x, List L)
{
    Position P, TmpCell;

    P = FindPrevious(x, L);

    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        delete(TmpCell);
    }
}

Position FindPrevious(ElementType x, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != x)
        P = P->Next;

    return P;
}

void Insert(ElementType x, List L, Position P)
{
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(Node));
    if(TmpCell == NULL)
        exit(1);

    TmpCell->Element = x;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}