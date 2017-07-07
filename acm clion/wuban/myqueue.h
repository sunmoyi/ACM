//
// Created by 孙启龙 on 2016/11/3.
//

#include "stdio.h"
#include "stdlib.h"

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW    -2

typedef int ElementType;
typedef int Status;

typedef struct node{
    ElementType date;
    node *next;
}node;

typedef struct {
    int size;
    node *tail = NULL;
    node *head = NULL;
}queue;

Status initqueue(queue *Q)
{
    Q->size = 0;
    Q->head = (node *)malloc(sizeof(node));
    if(!Q->head)
        return OVERFLOW;

    Q->head->next = NULL;
    Q->tail = Q->head;
    return OK;
}

Status GetTop(queue Q, ElementType *e)
{
    if(Q.size == 0)
        return ERROR;
    *e = Q.head->date;
    return OK;
}

Status Push(queue *Q, ElementType e)
{
    node *temp = (node *)malloc(sizeof(node));
    if(!temp)
        return OVERFLOW;

    temp->next = NULL;
    temp->date = e;
    Q->tail->next = temp;
    Q->tail = temp;
    Q->size++;
    return OK;
}

Status Pop(queue *Q, ElementType *e)
{
    if(Q->size == 0)
        return INFEASIBLE;

    node *temp = Q->head->next->next;
    *e = Q->head->next->date;

    if(Q->size == 1)
        Q->tail = Q->head;
    Q->head->next = temp;
    Q->size--;
}
