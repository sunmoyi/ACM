#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[3005];
int ans[1000 * 500];
int k, sum;

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	while (scanf("%d %d", &k, &sum) != EOF)
	{
		for (int i = 0; i < k; i++)
			scanf("%d", &num[i]);
		sort(num, num + k, cmp);
		int g = 0;
		for (int i = 0; i <= 500 && i < k; i++)
		{
			for (int j = i; j <= 500 && j < k; j++)
			{
				if (i != j)
				{
					ans[g++] = num[i] + num[j];
				}
			}
		}
		sort(ans, ans + g - 1, cmp);
		for (int i = 0; i < sum - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[sum - 1]);
	}
	return 0;
}