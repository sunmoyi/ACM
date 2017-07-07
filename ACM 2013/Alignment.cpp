#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int up[1005], down[1005];
double y[1005];
int sum;

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%lf", &y[i]);

		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));

		for (int i = 1; i <= sum; i++)
		{
			up[i] = 1;
			for (int j = i - 1; j >= 1; j--)
			{
				if (y[j] < y[i])
				{
					up[i] = max(up[i], up[j] + 1);
				}
			}
		}

		for (int i = sum; i >= 1; i--)
		{
			down[i] = 1;
			for (int j = i + 1; j <= sum; j++)
			{
				if (y[j] < y[i])
				{
					down[i] = max(down[i], down[j] + 1);
				}
			}
		}

		int temp = 0;
		for (int i = 1; i < sum; i++)
		{
			for (int j = i + 1; j <= sum; j++)
			{
				temp = max(up[i] + down[j], temp);
			}
		}
		printf("%d\n", sum - temp);
	}
	return 0;
}