#include<stdio.h>
long long recursion(int a, int b);
long long s[10000];
int vis[10000] = { 0 };
int main(void)
{
	int  num, i, k ;
	while (scanf_s("%d %d",&num) != EOF)
	{
		for (i = 1;; i++)
		{
			k = recursion(i, num);
			if (k == 0)
				continue;
			else
			{
				printf("%lld\n", k);
				break;
			}
		}
	}
	return 0;
}
long long recursion(int a, int b)
{
	s[b] = 5 * a + 1;

}