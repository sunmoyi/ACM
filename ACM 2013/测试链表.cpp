#include<stdio.h>
struct t{
	int a;
	t *b = NULL;
}i[100000];
int main(void)
{
	for (int j = 0; j < 100000; j++)
	{
		i[j].a = j;
	}
	for (int j = 0; j < 99999; j++)
		i[j].b = &i[j + 1];
	t *p;
	p = &i[0];
	while (p)
	{
		printf("%d\n", p->a);
		p = p->b;
	}
}