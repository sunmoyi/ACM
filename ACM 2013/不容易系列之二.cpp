#include <stdio.h>
int recursion(int b);
int a[30];
int vis[30] ={0};
int main (void)
{
	int n, m, i, j;
	while(scanf("%d",&n) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&j);
			m = recursion(j);
			printf("%d\n",m);
		}
	}
	return 0;
}
int recursion(int b)
{
	a[1] = 4;
	a[2] = 6;
	if(b <= 2 ||vis[b] == 1)
		return a[b];
	if(b > 2 && vis[b] != 1)
	{
		a[b] = ((recursion(b - 1) - 1) * 2);
		vis[b] = 1;
		return a[b];
	}
}