#include <stdio.h>
int recursion(int a);
int b[40];
int vis[40] = {0};
int main(void)
{
	int n, m, i, k;
	while(scanf("%d",&n) != EOF)
	{
		for( i = 1; i <= n ; i++)
		{
			scanf("%d",&m);
			k =  recursion(m - 1);
			printf("%d\n", k);
		}
	}
	return 0;
}
int recursion(int a)
{
	
	b[1] = 1;
	b[2] = 2;
	if(a <= 2 || vis[a] == 1)
		return b[a];
	if(a > 2 && vis[a] != 1)
	{
		b[a] = recursion(a - 1) + recursion(a - 2);
		vis[a] = 1;
		return b[a];
	}
}