#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1010
#define INF 0x3f3f3f3f
#define LEFT 0
#define RIGHT 1

using namespace std;

struct node {
	int x;
	double c, d;
	bool friend operator < (const node&a, const node&b)
	{
		return a.x < b.x;
	}
};

int n, v, sx;
node wall[maxn];
double pref_d[maxn], sumc, d[maxn][maxn][2];
int vis[maxn][maxn][2];
int icase = 0;

double cost(int l, int r, int s, int t)
{
	double result = 0.0;
	double sumd = pref_d[n] - (pref_d[r] - pref_d[l] + wall[l].d);
	int dist = abs(wall[s].x - wall[t].x);
	double time = dist * 1.0 / v;
	result = sumd * time;
	return result;
}

double dp(int l, int r, int k)
{
	if (l == 0 && r == n)
		return 0;
	double& ans = d[l][r][k];
	if (vis[l][r][k] == icase)
		return ans;
	vis[l][r][k] = icase;
	ans = INF;

	double s = (k == LEFT) ? l : r;
	if (l > 0)
		ans = min(ans, dp(l - 1, r, LEFT) + cost(l, r, s, l - 1));
	if (r < n)
		ans = min(ans, dp(l, r + 1, RIGHT) + cost(l, r, s, r + 1));
	return ans;
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	while (scanf("%d %d %d", &n, &v, &sx) != EOF && n)
	{
		icase++;
		wall[0].x = sx, wall[0].c = wall[0].d = 0;
		int sindex;
		sumc = 0;
		for (int i = 1; i < n + 1; i++)
		{
			scanf("%d%lf%lf", &wall[i].x, &wall[i].c, &wall[i].d);
			sumc += wall[i].c;
		}
		sort(wall, wall + n + 1);

		for (int i = 0; i < n + 1; i++)
		{
			if (wall[i].x == sx)
				sindex = i;

			pref_d[i] = wall[i].d;
			if (i)
				pref_d[i] += pref_d[i - 1];
		}
		printf("%.0f\n", floor(dp(sindex, sindex, LEFT) + (double)sumc));
	}
	return 0;
}