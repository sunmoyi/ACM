//
// Created by 孙启龙 on 2016/11/10.
//

#include<cstdio>
#include<cstring>

using namespace std;

struct BitTree{
    bool number;
    int leftchild, rightchild;
    int num;
    char oper;
}Tree[1000];

void initBitTree()
{
    for(int i = 1; i < 1000; i++)
        Tree[i].leftchild = Tree[i].rightchild = 0, Tree[i].number = true;
}

int add(int left, int right, int oper, int root)
{
    Tree[root].number = false;
    Tree[root].leftchild = left;
    Tree[root].rightchild = right;
    Tree[root].oper = oper;
    return root;
}

int cal(int a, int b, char c)
{
    if(c == '+')
        return a + b;
    if(c == '-')
        return a - b;
    if(c == '*')
        return a * b;
    if(c == '/')
        return a / b;
}

int calculate(int root)
{
    if(Tree[root].rightchild == 0 && Tree[root].leftchild == 0)
        return Tree[root].num;
    return cal(calculate(Tree[root].leftchild), calculate(Tree[root].rightchild), Tree[root].oper);
}