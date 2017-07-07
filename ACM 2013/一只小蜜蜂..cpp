#include<stdio.h>
long long ricursion (int a);
long long s[50];
int vis[50] = {0};
int main (void)
{
	int  n, a, b, i, j;
	long long k;
	while(scanf("%d",&n) != EOF)
	{
		//getchar();
		for(i = 1; i <= n; i++)
		{
			scanf("%d %d", &a,&b);
			k = ricursion(b - a + 1);
			printf("%lld\n",k);
		}
	}
	return 0;
}
long long ricursion (int a)
{
	s[1] = 1;
	s[2] = 1;
	s[3] = 2;
	if(a <= 3 ||vis[a] == 1)
		return s[a];
	else
	{
		s[a] = ricursion(a - 1) + ricursion(a  - 2);
		vis[a] = 1;
		return s[a];
	}
}