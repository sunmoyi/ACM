#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int x1, x2, high;
};
int N, X, Y, MAX;
node plat[maxn];
int dp[maxn][2];

int cmp(node a ,node b)
{
	return a.high < b.high;
}

void leftmintime(int i)
{
	int k = i - 1;
	while (k > 0 && plat[i].high - plat[k].high <= MAX)
	{
		if (plat[i].x1 >= plat[k].x1 && plat[i].x1 <= plat[k].x2)
		{
			dp[i][0] = plat[i].high - plat[k].high +
				min(plat[i].x1 - plat[k].x1 + dp[k][0], plat[k].x2 - plat[i].x1 + dp[k][1]);
			return;
		}
		else
			k--;
	}
	if (plat[i].high - plat[k].high > MAX)
		dp[i][0] = INF;
	else
		dp[i][0] = plat[i].high;
}

void rightmintime(int i)
{
	int k = i - 1;
	while (k > 0 && plat[i].high - plat[k].high <= MAX) 
	{
		if (plat[i].x2 >= plat[k].x1 && plat[i].x2 <= plat[k].x2)
		{
			dp[i][1] = plat[i].high - plat[k].high +
				min(plat[i].x2 - plat[k].x1 + dp[k][0], plat[k].x2 - plat[i].x2 + dp[k][1]);
			return;
		}
		else
			--k;
	}

	if (plat[i].high - plat[k].high > MAX)
		dp[i][1] = INF;
	else
		dp[i][1] = plat[i].high;
}

int sorttesttime()
{
	int i, j;
	for (i = 1; i <= N + 1; i++)
	{
		leftmintime(i);
		rightmintime(i);
	}
	return min(dp[N + 1][0], dp[N + 1][1]);
}

int main(void)
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d %d %d %d", &N, &X, &Y, &MAX);
			for (int i = 1; i <= N; i++)
				scanf("%d %d %d", &plat[i].x1, &plat[i].x2, &plat[i].high);
			plat[0].high = 0;
			plat[0].x1 = -20000;
			plat[0].x2 = 20000;
			plat[N + 1].high = Y;
			plat[N + 1].x1 = X;
			plat[N + 1].x2 = X;
			sort(plat, plat + N + 2, cmp);
			printf("%d\n", sorttesttime());
		}
	}
	return 0;
}