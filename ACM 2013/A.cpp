#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1049000][2];

int main(void)
{
	int ans, a, b;
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d", &a, &b);

			long long timee = pow(2, a);
			long long change = pow(2, b) - 1;
			for (int i = 1; i <= timee; i++)
			{
				for (int j = 1; j <= timee / 2 + 1; j++)
				{
					
				}
			}
		}
	}
}