//
// Created by 孙启龙 on 16/10/23.
//

#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>

using namespace std;
//  栈的顺序存储表示
#define MAXSIZE 10 // 存储空间初始分配量

typedef struct SqStack
{
    char *base; // 在栈构造之前和销毁之后，base的值为NULL
    char *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

void InitStack(SqStack &S)
{ // 构造一个空栈S
    S.base=new char[MAXSIZE];
    S.top=S.base;
    S.stacksize=MAXSIZE;
}

void Push(SqStack &S,char e)
{ // 插入元素e为新的栈顶元素
    *S.top = e;
    S.top++;
}

char Pop(SqStack &S,char &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    e = *(--S.top) ;
    return e;
}

bool In(char ch){
    //判定读入的字符ch是否为运算符
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#')
        return true;
    return false;
}
char Precede(char c1,char c2){
    //判断运算符栈的栈顶元素的读入的运算符之间优先关系
    if((c1 == '+' || c1 == '-' ) && (c2 == '*' || c2 == '/'))//先乘除后加减
        return '<';
    if((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-'))//先乘除后加减
        return '>';
    if((c1 == '+' && c2 == '+') || (c1 == '-' && c2 == '-') //运算符相同，遵循左结合性
       || (c1 == '*' && c2 == '*') || (c1 == '/' && c2 == '/'))
        return '>';
    if((c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/') && (c2 == '('))//加减乘除的优先性低于'('
        return '<';
    if((c1 == '(' || c1 == '#') && (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/'))//加减乘除的优先性低于'('及'#'
        return '<';
    if((c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/') && (c2 == ')' || c2 == '#'))//加减乘除的优先性高于')'及'#'
        return '>';
    if((c1 == ')') && (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/'))//加减乘除的优先性高于')'
        return '>';
    if(c1 == '(' && c2 == ')')
        return '=';
    if(c1 == '#' && c2 == '#')
        return '=';
}
char Operate(char a,char ch,char b){
    int x = a - '0';
    int y = b - '0';
    int result;
    char cresult;
    //进行二元运算的函数
    if(ch=='+')
        result = x + y;
    if(ch=='-')
        result = x - y;
    if(ch=='*')
        result = x * y;
    if(ch=='/')
        result = x / y;
    cresult = result + '0';
    return cresult;
}
char GetTop(SqStack S)
{ // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if(S.top != S.base){//栈非空
        return *(S.top - 1);}	//返回栈顶元素的值，栈顶指针不变
}
char EvaluateExpression(){
    //算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈
    SqStack OPND, OPTR;
    char ch;
    char theta, x;//算术表达式的符号
    char a, b;//算术表达式的数字
    InitStack(OPND);//初始化OPND栈
    InitStack(OPTR);//初始化OPTR栈
    Push(OPTR, '#');//将表达式起始符'#'压入OPTR栈
    cin>>ch;
    while(ch != '#' || GetTop(OPTR) != '#'){//表达式没有扫描完毕或者OPTR的栈顶元素不为'#'
        if(!In(ch)){Push(OPND,ch);cin>>ch;}
        else
            switch(Precede(GetTop(OPTR),ch)){//比较OPTR的栈顶元素和ch的优先级
                case '<':
                    Push(OPTR,ch);
                    cin>>ch;//当前字符ch压入OPTR栈，读入下一字符ch
                    break;
                case '>':
                    Pop(OPTR,theta);//弹出OPTR栈顶的运算符
                    Pop(OPND,b);
                    Pop(OPND,a);//弹出OPND栈顶的两个运算数
                    Push(OPND,Operate(a, theta, b));//将运算结果压入OPND栈
                    break;
                case '='://OPTR的栈顶元素是"("且ch是")"
                    Pop(OPTR,x);
                    cin>>ch;//弹出OPTR栈顶的"("，读入下一字符ch
                    break;
            }//switch
    }//while
    return GetTop(OPND);//OPND栈顶元素即为表达式求值的结果
}

int main(){

    cout << EvaluateExpression() << endl;
    return 0;
}