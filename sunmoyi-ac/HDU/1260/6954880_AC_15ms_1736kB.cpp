#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[2010];
int num1[2010], num2[2010];
int n, k;

int main(void)
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
			scanf("%d", &num1[i]);
		for (int i = 2; i <= k; i++)
			scanf("%d", &num2[i]);

		dp[0] = 0;
		dp[1] = num1[1];
		for (int i = 2; i <= k; i++)
			dp[i] = min(dp[i - 1] + num1[i], dp[i - 2] + num2[i]);

		int temp = dp[k] + 8 * 3600;
		int ans1 = temp / 3600;
		temp %= 3600;
		int ans2 = temp / 60;
		temp %= 60;
		int ans3 = temp;

		bool flag = false;
		if (ans1 >= 12)
		{
			ans1 %= 12;
			flag = true;
		}

		printf("%02d:%02d:%02d %s\n", ans1, ans2, ans3, flag ? "pm" : "am");
	}
	return 0;
}