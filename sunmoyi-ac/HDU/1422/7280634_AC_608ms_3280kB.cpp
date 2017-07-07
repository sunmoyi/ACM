#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, dp[200010], t1, t2;
int maxx;
int a[200010];

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		for (int i = 1; i <= ans; i++)
		{
			scanf("%d %d", &t1, &t2);
			a[i] = a[ans + i] = t1 - t2;
		}

		memset(dp, 0, sizeof(dp));
		maxx = 0;
		int t = 0, temp = 0;

		for (int i = 1; i <= ans * 2; i++)
		{
			t += a[i];
			temp++;
			if (t < 0)
			{
				t = 0;
				temp = 0;
			}
			maxx = max(maxx, temp);
			if (temp >= ans)
				break;
		}
		printf("%d\n", maxx);
	}
	return 0;
}