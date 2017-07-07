#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int x, y;
	double len;
	node(int x = 0, int y = 0, double len = 0) :x(x), y(y), len(len) {}
	bool friend operator < (const node &a, const node &b)
	{
		return a.len < b.len;
	}
}dis[100000];

int father[210];
double site[210][3];
int ans;

void init(int n)
{
	for (int i = 0; i <= n; i++)
		father[i] = i;
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	father[x] = y;
	return true;
}

int main(void)
{
	int icase = 1;
	while (scanf("%d", &ans) != EOF && ans)
	{
		init(ans + 1);
		for (int i = 1; i <= ans; i++)
		{
			scanf("%lf %lf", &site[i][1], &site[i][2]);
		}
		int sum = 0;
		double maxx = 0xfffffff;
		for (int i = 1; i <= ans; i++)
		{
			for (int j = i + 1; j <= ans; j++)
			{
				dis[sum].x = i;
				dis[sum].y = j;
				dis[sum++].len = sqrt((site[i][1] - site[j][1]) * (site[i][1] - site[j][1]) + (site[i][2] - site[j][2]) * (site[i][2] - site[j][2]));
			}
		}

		sort(dis, dis + sum);

		for (int i = 0; i < sum; i++)
		{
			if (unoin(dis[i].x, dis[i].y))
			{
				if (find(1) == find(2))
				{
					maxx = dis[i].len;
					break;
				}
			}
		}
		printf("Scenario #%d\n", icase++);
		printf("Frog Distance = %.3lf\n\n", maxx);
	}
	return 0;
}