//
// Created by 孙启龙 on 16/10/23.
//

#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;/*单项链表的声明*/

typedef struct PolynNode
{
    int coef; // 系数  搜索
    int expn; // 指数
    bool minu = false;
    struct PolynNode *next;
}
        PolynNode, *PolynList;/*正位序(插在表尾)输入n个元素的值，建立带表头结构的单链线性表*/

void CreatePolyn(PolynList &L, int n)
{
    int i;
    PolynList list, q;
    list = L = (PolynList)malloc(sizeof(PolynNode)); // 生成头结点
    list->next = NULL;
    for (i = 1; i <= n; i++)
    {
        q = (PolynList)malloc(sizeof(PolynNode));
        q->minu = false;
        scanf("%d %d", &q->coef, &q->expn);    //指数和系数成对输入
        list->next = q;
        list = list->next;
    }
    list->next = NULL;
}

void PolynTraverse(PolynList L)
{
    PolynList p = L->next;
    if(p->minu)
        printf("-");
    printf("%dX^%d", p->coef, p->expn);
    p = p->next;
    while (p != NULL)
    {
        if(p->minu)
            printf(" - ");
        else
            printf(" + ");//“+”号的输出，最后一项后面没有“+”
        printf("%dX^%d", p->coef, p->expn);
        p = p->next;
    }
    printf("\n\n");
}

PolynList mergeList(PolynList La, PolynList Lb)
{
    PolynList pa, pb, pc, Lc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;   // 用La的头结点作为Lc的头结点
    while (pa&&pb)
    {
        if (pa->expn < pb->expn)
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pa->coef, temp->expn = pa->expn, temp->minu = false;
            pc->next = temp;             //如果指数不相等，pc指针连上指数小的结点，
            pc = temp;
            pa = pa->next;             //指向该结点的指针后移
        }
        else if (pa->expn > pb->expn)
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pb->coef, temp->expn = pb->expn; temp->minu = true;
            pc->next = temp;               //pc指针连上指数小的结点，
            pc = temp;
            pb = pb->next;               //指向该结点的指针后移
        }
        else   //(pa ->expn == pb->expn )
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pa->coef - pb->coef, temp->expn = pb->expn;    //指数相等时，系数相加
            if(temp->coef > 0)
                temp->minu = false;
            else
            {
                temp->minu = true;
                temp->coef = -(temp->coef);
            }
            pc->next = temp;
            pc = temp;
            pa = pa->next;             //两指针都往后移
            pb = pb->next;
        }
    }
    if (pa != NULL)// 插入剩余段
        pc->next = pa;
    else
    {
        pc->next = pb;
        while(pc->next != NULL)
        {
            pc->minu = true;
            pc = pc->next;
        }
    }
    return Lc;
}

PolynList MergeList(PolynList La, PolynList Lb)
{
    PolynList pa, pb, pc, Lc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;   // 用La的头结点作为Lc的头结点
    while (pa&&pb)
    {
        if (pa->expn < pb->expn)
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pa->coef, temp->expn = pa->expn;
            if(temp->coef > 0)
                temp->minu = false;
            else
            {
                temp->minu = true;
                temp->coef = -(temp->coef);
            }
            pc->next = temp;             //如果指数不相等，pc指针连上指数小的结点，
            pc = temp;
            pa = pa->next;             //指向该结点的指针后移
        }
        else if (pa->expn > pb->expn)
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pb->coef, temp->expn = pb->expn;
            if(temp->coef > 0)
                temp->minu = false;
            else
            {
                temp->minu = true;
                temp->coef = -(temp->coef);
            }
            pc->next = temp;               //pc指针连上指数小的结点，
            pc = temp;
            pb = pb->next;               //指向该结点的指针后移
        }
        else   //(pa ->expn == pb->expn )
        {
            PolynNode *temp = (PolynNode *)malloc(sizeof(PolynNode));
            temp->coef = pb->coef + pa->coef, temp->expn = pb->expn;    //指数相等时，系数相加
            if(temp->coef > 0)
                temp->minu = false;
            else
            {
                temp->minu = true;
                temp->coef = -(temp->coef);
            }
            pc->next = temp;
            pc = temp;
            pa = pa->next;             //两指针都往后移
            pb = pb->next;
        }
    }
    if (pa != NULL)// 插入剩余段
    {
        pc->next = pa;
        while(pc->next != NULL)
        {
            if(pc->coef < 0)
            {
                pc->minu = true;
                pc->coef = -(pc->coef);
            }
            pc = pc->next;
        }
    }
    else
    {
        pc->next = pb;
        while(pc->next != NULL)
        {
            if(pc->coef < 0)
            {
                pc->minu = true;
                pc->coef = -(pc->coef);
            }
            pc = pc->next;
        }
    }
    return Lc;
}

int  main()
{
    PolynList ha, hb, hc;
    int n, m, cmd;
    printf("请输入多项式1的项数\n");
    scanf("%d", &n);
    printf("非递减输入多项式ha， 成对输入%d个数据\n", n);
    CreatePolyn(ha, n);   // 正位序输入n个元素的值
    printf("请输入多项式2的项数\n");
    scanf("%d", &m);
    printf("非递减输入多项式hb， 成对输入%d个数据\n", m);
    CreatePolyn(hb, m);   // 正位序输入n个元素的值
    printf("多项式ha :");
    PolynTraverse(ha);
    printf("多项式hb :");
    PolynTraverse(hb);
    //printf("1\n");
    printf("1为减法, 2为加法\n");
    scanf("%d", &cmd);
    if(cmd == 1)
    {
        hc = mergeList(ha, hb);
        PolynTraverse(hc);
    }
    else
    {
        hc = MergeList(ha, hb);
        PolynTraverse(hc);
    }
    return 0;
}