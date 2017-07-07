#include <stdio.h>
long long recursion(int a);
long long b[50];
int vis[50] = {0};
int main(void)
{
	int n;
	long long i;
	while(scanf("%d",&n) != EOF)
	{
		i = recursion(n);
		printf("%lld\n",i);
	}
	return 0;
}
long long recursion(int a)
{

	b[1] = 1;
	b[2] = 2;
	if(a <= 2 ||vis[a] == 1)
		return b[a];
	else
	{
		b[a] = recursion(a - 1) + recursion(a - 2);
		vis[a] = 1;
		return b[a];
	}
}