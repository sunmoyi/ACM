#include<iostream>
#include<stdlib.h>
using namespace std;
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef char SElemType; // 栈元素为字符型
//  栈的顺序存储表示
#define MAXSIZE 10 // 存储空间初始分配量
typedef struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

//  顺序栈的基本操作(9个)
void InitStack(SqStack &S)
{ // 构造一个空栈S
	if (!(S.base = new SElemType[MAXSIZE]))
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = MAXSIZE;
}

void DestroyStack(SqStack &S)
{ // 销毁栈S，S不再存在
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{ // 把S置为空栈
	S.top = S.base;
}

Status StackEmpty(SqStack S)
{ // 若栈S为空栈，则返回TRUE，否则返回FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)
{ // 返回S的元素个数，即栈的长度
	return S.top - S.base;
}

SElemType GetTop(SqStack S)
{ // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top != S.base)
		return *(S.top - 1);
}

Status Push(SqStack &S, SElemType e)
{ // 插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize) // 栈满，追加存储空间
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}

void StackTraverse(SqStack S)
{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()
	SElemType *p;
	p = S.base;
	while (p<S.top)
	{
		cout << *p;
		p++;

	}
	cout << endl;
}
typedef struct BiNode{

	char data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;
//  栈的顺序存储表示
#define MAXSIZE 10 // 存储空间初始分配量
typedef struct EXPTStack
{
	BiTree *base; // 在栈构造之前和销毁之后，base的值为NULL
	BiTree *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}EXPTStack; // 顺序栈

//  顺序栈的基本操作(9个)
void InitStack(EXPTStack &S)
{ // 构造一个空栈S
	if (!(S.base = new BiTree[MAXSIZE]))
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = MAXSIZE;
}

void DestroyStack(EXPTStack &S)
{ // 销毁栈S，S不再存在
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

void ClearStack(EXPTStack &S)
{ // 把S置为空栈
	S.top = S.base;
}

Status StackEmpty(EXPTStack S)
{ // 若栈S为空栈，则返回TRUE，否则返回FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(EXPTStack S)
{ // 返回S的元素个数，即栈的长度
	return S.top - S.base;
}

BiTree GetTop(EXPTStack S)
{ // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top != S.base)
		return *(S.top - 1);
}

Status Push(EXPTStack &S, BiTree e)
{ // 插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize) // 栈满，追加存储空间
		return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(EXPTStack &S, BiTree &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}

void StackTraverse(EXPTStack S)
{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()
	BiTree *p;
	p = S.base;
	while (p<S.top)
	{
		cout << *p;
		p++;

	}
	cout << endl;
}


char Precede(SElemType t1, SElemType t2)
{ // 根据教科书表3.1，判断t1，t2两符号的优先关系
	char f;
	switch (t2)
	{
	case '+':
	case '-':if (t1 == '(' || t1 == '#')
		f = '<'; // t1<t2
			 else
				 f = '>'; // t1>t2
		break;
	case '*':
	case '/':if (t1 == '*' || t1 == '/' || t1 == ')')
		f = '>'; // t1>t2
			 else
				 f = '<'; // t1<t2
		break;
	case '(':if (t1 == ')')
	{
		cout << "括号不匹配" << endl;
		exit(ERROR);
	}
			 else
				 f = '<'; // t1<t2
		break;
	case ')':switch (t1)
	{
	case '(':f = '='; // t1=t2
		break;
	case'#':cout << "缺乏左括号" << endl;
		exit(ERROR);
	default:f = '>';  break; // t1>t2
	}
			 break;
	case'#':switch (t1)
	{
	case'#':f = '='; // t1=t2
		break;
	case'(':cout << "缺乏右括号" << endl;
		exit(ERROR);
	default:f = '>'; // t1>t2
	}
	}
	return f;
}

Status In(SElemType c)
{ // 判断c是否为7种运算符之一
	switch (c)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':return TRUE;
	default:return FALSE;
	}
}

int GetValue(SElemType theta, SElemType a, SElemType b)
{ // 做四则运算a theta b，返回运算结果

	switch (theta)
	{
	case'+':return a + b;
	case'-':return a - b;
	case'*':return a*b;
	case '/': return a / b;
	}

}
void CreateExpTree(BiTree &T, BiTree a, BiTree b, char theta){
	//创建以theta为根，以a为左子树，b为右子树的二叉树
	T = new BiNode;
	T->data = theta;
	T->lchild = a;
	T->rchild = b;

}

void  InitExpTree(BiTree &T){//创建表达式树
	SqStack OPTR;
	EXPTStack EXPT;
	char ch, theta, x;
	BiTree a, b;
	InitStack(EXPT);//初始化运算符栈OPTR
	InitStack(OPTR);//初始化表达式栈EXPT
	Push(OPTR, '#');//将‘#’压人OPTR
	cin >> ch;
	while (ch != '#' || GetTop(OPTR) != '#'){//当栈顶元素不为‘#’或者ch不为‘#’
		if (!In(ch)){ //ch不是运算符
			CreateExpTree(T, NULL, NULL, ch);//以ch为根创建只有根结点的二叉树
			Push(EXPT, T);//将指向二叉树根结点的指针T压入EXPT栈
			cin >> ch;
		}
		else //ch为运算符
			switch (Precede(GetTop(OPTR), ch)){//比较OPTR栈顶元素和ch的优先级
			case '<'://OPTR的栈顶元素的优先级小于ch的优先级
				Push(OPTR, ch);//ch压人OPTR栈中
				cin >> ch;
				break;
			case '>'://OPTR的栈顶元素的优先级大于ch的优先级
				Pop(OPTR, theta);//弹出运算符栈OPTR的栈顶元素theta
				Pop(EXPT, b);
				Pop(EXPT, a);//弹出EXPT栈的两个栈顶元素a和b
				CreateExpTree(T, a, b, theta);//创建以theta为根，a和b分别为左右子树的二叉树T
				Push(EXPT, T);//将T压入EXPT栈
				break;
			case '='://OPTR的栈顶元素是‘（’，ch为')'
				Pop(OPTR, x);//脱掉括号
				cin >> ch;
				break;
		}
	}

}
int EvalateExpTree(BiTree T){

	int lvalue, rvalue;
	lvalue = rvalue = 0;
	if (T->lchild == NULL&&T->rchild == NULL)//T为叶子
		return T->data - '0';
	else
	{
		lvalue = EvalateExpTree(T->lchild);//递归计算左子树的值，保存到lvalue
		rvalue = EvalateExpTree(T->rchild);//递归计算右子树的值，保存到rvalue
		return GetValue(T->data, lvalue, rvalue);//根据T->data运算符的类型进行相应的计算

	}
}


int main(){
	BiTree T;
	InitExpTree(T);//创建表达式树
	cout << EvalateExpTree(T);//利用表达式树对表达式求值
}