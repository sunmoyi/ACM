#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100019];
int sum;
int n;
int ans[100010];
int maxx;

int main(void)
{
	while (scanf("%d %d", &n, &sum) != EOF)
	{
		maxx = 0;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		num[n + 1] = sum + 1;

		sort(num + 1, num + 2 + n);

		int kk = 1, kkk = 1;
		while (sum > kk)
		{
			long long summ = 0;
			for (int i = num[kkk - 1] + 1; i < num[kkk]; i++)
				summ += i;
			if (sum > summ)
			{
				sum -= summ;

				for (int i = num[kkk - 1] + 1; i < num[kkk]; i++)
					ans[maxx++] = i;
				kkk++;
				kk = ans[maxx - 1];
			}
			else
			{
				for (int i = num[kkk - 1] + 1; i < num[kkk]; i++)
				{
					if (sum >= i)
					{
						ans[maxx++] = i;
						sum -= i;
						kk = ans[maxx - 1];
					}
					else
						break;
				}
			}
		}

		bool flag = false;
		int i;
		for (i = sum; i > 0; i--)
		{
			int tt = ans[maxx - 1] + i;
			for (int j = kkk - 1; j <= kkk + sum && kkk <= n; j++)
			{
				if (num[j] < tt && num[j + 1] > tt)
				{
					flag = true;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		ans[maxx - 1] += i;
		printf("%d\n", maxx );
		for (int i = 0; i < maxx - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[maxx - 1]);
	}
	return 0;
}