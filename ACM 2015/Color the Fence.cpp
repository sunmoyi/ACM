#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10

using namespace std;

int a[maxn];
int top;
int sum, minn, maxx, site;
char ans[1000000 + 1];

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		minn = 0x3f3f3f3f;
		for (int i = 1; i <= 9; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] <= minn)
			{
				minn = a[i];
				site = i;
			}
		}
		if (minn > sum)
		{
			printf("-1\n");
			continue;
		}

		maxx = (sum / minn);
		int k = sum - maxx * minn;
		for (int i = 1; i <= maxx; i++)
			ans[i] = site;
		int i = 1;
		while (i <= maxx && k > 0)
		{
			k += minn;
			for (int j = 9; j >= ans[i]; j--)
			{
				if (a[j] <= k)
				{
					ans[i] = j;
					k -= a[j];
					break;
				}
			}
			i++;
		}
		for (int i = 1; i < maxx; i++)
			printf("%d", ans[i]);
		printf("%d\n", ans[maxx]);
	}
	return 0;
}