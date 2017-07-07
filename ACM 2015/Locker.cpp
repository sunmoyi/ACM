#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#include <functional>  

using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
char str1[maxn];
char str2[maxn];
int a[maxn];
int b[maxn];
int dp[maxn][10][10];
int len;

int up(int s, int t)             //上旋  
{
	if (s >= t)
		return s - t;
	else
		return (s - t + 10) % 10;
}


int down(int s, int t)          //下旋  
{
	if (t >= s)
		return t - s;
	else
		return (t - s + 10) % 10;
}

int DFS(int cur, int t1, int t2)
{
	if (cur >= len)
		return 0;
	if (dp[cur][t1][t2] != -1)
		return dp[cur][t1][t2];
	int t = up(b[cur], t1);
	int ans = INF;

	for (int i = 0; i <= t; i++)            //枚举后个数的情况  
		for (int j = i; j <= t; j++)
		{
			ans = min(ans, DFS(cur + 1, (t2 + j) % 10, (a[cur + 2] + i) % 10) + t);
		}

	t = down(b[cur], t1);
	for (int i = 0; i <= t; i++)
		for (int j = i; j <= t; j++)
		{
			ans = min(ans, DFS(cur + 1, (t2 - j + 10) % 10, (a[cur + 2] - i + 10) % 10) + t);
		}
	return dp[cur][t1][t2] = ans;
}


int main()
{
	while (scanf("%s%s", str1, str2) != EOF)
	{
		len = strlen(str1);
		for (int i = 0; i < len; i++)
		{
			a[i] = str1[i] - '0';
			b[i] = str2[i] - '0';
		}
		a[len] = a[len + 1] = b[len] = b[len + 1] = 0;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", DFS(0, a[0], a[1]));
	}
	return 0;
}