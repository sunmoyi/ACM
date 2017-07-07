#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct PNode {
	int coef;
	int expn;
	struct PNode * next;
}PNode, *Polynomial;

Polynomial AddPolyn(Polynomial &A, Polynomial &B)
{
	PNode *Polynomiala = A->next, *Polynomialb = B->next, *temp, *start, *Polynomialc;
	start = Polynomialc = (PNode *)malloc(sizeof(PNode));

	while (Polynomiala != NULL && Polynomialb != NULL)
	{
		if (Polynomiala->expn < Polynomialb->expn)
		{
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = Polynomiala->coef;
			temp->expn = Polynomiala->expn;
			Polynomialc->next = temp;
			Polynomiala = Polynomiala->next;
		}
		else if (Polynomiala->expn > Polynomialb->expn)
		{
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = Polynomialb->coef;
			temp->expn = Polynomialb->expn;
			Polynomialc->next = temp;
			Polynomialb = Polynomialb->next;
		}
		else
		{
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = Polynomiala->coef + Polynomialb->coef;
			temp->expn = Polynomiala->expn;
			Polynomialc->next = temp;
			Polynomiala = Polynomiala->next;
			Polynomialb = Polynomialb->next;
		}
		Polynomialc = Polynomialc->next;
	}

	if (Polynomiala != NULL)
	{
		while (Polynomiala != NULL)
		{
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = Polynomiala->coef;
			temp->expn = Polynomiala->expn;
			Polynomialc->next = temp;
			Polynomialc = Polynomialc->next;
			Polynomiala = Polynomiala->next;
		}
	}
	if (Polynomialb != NULL)
	{
		while (Polynomialb != NULL)
		{
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = Polynomialb->coef;
			temp->expn = Polynomialb->expn;
			Polynomialc->next = temp;
			Polynomialc = Polynomialc->next;
			Polynomialb = Polynomialb->next;
		}
	}
	Polynomialc->next = NULL;
	return start;
}

void insert(Polynomial A)
{
	Polynomial P = A;
	for (int i = 1; i <= 5; i++)
	{
		PNode * temp = (PNode *)malloc(sizeof(PNode));
		scanf("%d %d", &(temp->coef), &(temp->expn));
		P ->next = temp;
		P = P->next;
	}
	P->next = NULL;
}

void print(Polynomial A)
{
	Polynomial P = A->next;
	while (P)
	{
		printf("%dX^%d ", P->coef, P->expn);
		if (P->next)
			printf(" + ");
		P = P->next;
	}
	printf("\n\n");
}

int main(void)
{
	Polynomial A = (PNode *)malloc(sizeof(PNode));
	Polynomial B = (PNode *)malloc(sizeof(PNode));
	Polynomial C;
	printf("请输入5个表达式 要求次数递增\n");
	insert(A);
	print(A);
	printf("请输入5个表达式 要求次数递增\n");
	insert(B);
	print(B);
	C = AddPolyn(A, B);
	print(C);
	return 0;
}