#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define LEFT 0
#define RIGHT 1
#define maxn 1010

using namespace std;

struct node {
	int x;
	double c, d;
	bool friend operator < (const node&a, const node&b)
	{
		return a.x < b.x;
	}
};

int n, v, sx, icase = 0;
node wall[maxn];
double pre[maxn], sumc, dp[maxn][maxn][2];
int vis[maxn][maxn][2];

double cost(int l, int r, int s, int t)
{
	double result = 0;
	double sumb = pre[n] - (pre[r] - pre[l] + wall[l].d);
	int dist = abs(wall[s].x - wall[t].x);
	double time = dist * 1.0 / v;
	result = time * sumb;
	return result;
}

double dpp(int l, int r, int k)
{
	if (l == 0 && r == n)
		return 0;
	double &ans = dp[l][r][k];
	if (vis[l][r][k] == icase)
		return ans;
	vis[l][r][k] = icase;
	ans = INF;

	double s = (k == LEFT) ? l : r;
	if (l > 0)
		ans = min(ans, dpp(l - 1, r, LEFT) + cost(l, r, s, l - 1));
	if (r < n)
		ans = min(ans, dpp(l, r + 1, RIGHT) + cost(l, r, s, r + 1));
	return ans;
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	while (scanf("%d %d %d", &n, &v, &sx) != EOF && n)
	{
		icase++;

		wall[0].x = sx; wall[0].c = wall[0].d = 0;
		int index;
		sumc = 0;
		for (int i = 1; i < n + 1; i++)
		{
			scanf("%d %lf %lf", &wall[i].x, &wall[i].c, &wall[i].d);
			sumc += wall[i].c;
		}
		sort(wall, wall + n + 1);

		for (int i = 0; i < n + 1; i++)
		{
			if (wall[i].x == sx)
				index = i;
			pre[i] = wall[i].d;
			if (i)
				pre[i] += pre[i - 1];
		}
		printf("%.0f\n", floor(dpp(index, index, LEFT) + (double)sumc));
	}
	return 0;
}