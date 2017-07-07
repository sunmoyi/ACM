# include <stdio.h>
long long  ricursion (int b);
long long a[31];
int vis[31] = {0};
int main (void)
{
    long long a, sum;
	while(scanf("%lld", &a) != EOF)
	{
		sum = ricursion(a);
		printf("%lld\n", sum);
	}
	return 0;
}
long long ricursion (int b)
{
	a[1] = 1;
	a[2] = 4;
	if(b <= 2 || vis[b] == 1)
		return a[b];
	else
	{
		a[b] = (ricursion(b - 1) + 1 ) * 2;
		vis[b] = 1;
		return a[b];
	}
}













