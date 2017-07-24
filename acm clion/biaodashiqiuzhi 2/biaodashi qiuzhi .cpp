//
// Created by 孙启龙 on 2016/11/3.
//

#include <ctype.h>
#include "mystack.h"
#include"myBitTree.h"

int tot = 0;
char Precede(char a, char b)
{
    int i,j;
    char pre[][7]={
            {'>','>','<','<','<','>','>'},
            {'>','>','<','<','<','>','>'},
            {'>','>','>','>','<','>','>'},
            {'>','>','>','>','<','>','>'},
            {'<','<','<','<','<','=','0'},
            {'>','>','>','>','0','>','>'},
            {'<','<','<','<','<','0','='}};
    switch(a)
	{
        case '+': i=0; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=3; break;
        case '(': i=4; break;
        case ')': i=5; break;
        case '#': i=6; break;
    }
    switch(b)
	{
        case '+': j=0; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=3; break;
        case '(': j=4; break;
        case ')': j=5; break;
        case '#': j=6; break;
    }

    return pre[i][j];
}

int Operate(int a, char theta, int b)
{
    int i, j, result;
    i = a;
    j = b;

    switch(theta)
    {
        case '+':
            result = i + j;
            break;
        case '-':
            result = i - j;
            break;
        case '*':
            result = i * j;
            break;
        case '/':
            if(j == 0)
                return ERROR;
            result = i / j;
            break;
    }
    return result;
}

int getNext(int *n)
{
    char c;
    *n=0;
    while((c = getchar()) == ' ');
    if(!isdigit(c))
    {
        *n=c;
        return 1;
    }

    do{
        *n = *n * 10 + (c - '0');
        c = getchar();
    }while(isdigit(c));
	ungetc(c, stdin);
    return 0;
}

int EvaluateExpression()
{
    int n;
    int flag;
    int c;
    int x,theta;
    int a,b;

    char OP[] = "+-*/()#";
    SqStack OPTR;
    SqStack OPND;
    InitStack(&OPTR);
    Push(&OPTR,'#');
    InitStack(&OPND);
    flag=getNext(&c);

    GetTop(OPTR, &x);
    while(c!='#' || x != '#')
    {
        if(flag == 0)
        {
            Tree[tot].num = c;
            Push(&OPND, tot);
            tot++;
            flag = getNext(&c);
        }
        else
        {
            GetTop(OPTR, &x);
            switch(Precede(x, c))
            {
                case '<'://栈顶元素优先级低
                    Push(&OPTR, c);
                    flag = getNext(&c);
                    break;
                case '='://括号
                    Pop(&OPTR, &x);
                    flag = getNext(&c);
                    break;
                case '>':// 退栈并将运算结果入栈
                    Pop(&OPTR, &theta);
                    Pop(&OPND, &a);
                    Pop(&OPND, &b);
                    Push(&OPND, add(b, a, theta, tot));
                    tot++;
                    break;
            }
        }
        GetTop(OPTR, &x);
    }
    //GetTop(OPND, &c);
    return calculate(tot - 1);
}

int main()
{
    int c;
    initBitTree();
    tot = 0;
    printf("Please input one expression ended by '#':\n");
    c = EvaluateExpression();
    printf("Result = %d\n",c);
    getchar();
    return 0;
}
