#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char str[maxn];
int dp[maxn];
int n, a, b;

int main (void)
{
	while (scanf("%s", str + 1) != EOF)
	{
		for (int i = 1; str[i] != 0; i++)
			dp[i] = dp[i - 1] + (str[i] == str[i + 1]);
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", dp[b - 1] - dp[a - 1]);
		}
	}
	return 0;
}
//0 4 4
//1 2 5
//2 3 3
//3 1 4
//4 2 2
//5 0 3