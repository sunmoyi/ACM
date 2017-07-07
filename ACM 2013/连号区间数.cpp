#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int a[100000];
	int t, i, j, k, l;
	int maxn, minn, count;
	while (scanf("%d", &t) != EOF)
	{
		for (i = 1; i <= t; i++)
		{
			count = 0;
			scanf("%d", &j);
			for (k = 1; k <= j; k++)
				scanf("%d", &a[k]);
			for (int n = 1; n <= j; n++)
			{
				maxn = minn = a[n];
				for (int m = n; m <= j; m++)
				{
					maxn = max(maxn, a[m]);
					minn = min(minn, a[m]);
					if (maxn - minn == m - n)
						count++;
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}