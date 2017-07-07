#include <stdio.h>
long long ricursion (int a);
long long b[50];
int vis[50];
int main (void)
{
	int n;
	long long i;
	while(scanf("%d",&n) != EOF)
	{
		i = ricursion(n);
		printf("%lld\n",i);
	}
	return 0;
}
long long ricursion (int a)
{
	b[1] = 3;
	b[2] = 6;
	b[3] = 6;
	if(a <= 3|| vis[a] == 1 )
		return b[a];
	else
	{
		b[a] = ricursion(a -1) + 2 * (ricursion(a - 2));
		vis[a] = 1;
		return b[a];
	}
}
