#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int x;
	int y;
	double len;
	node(int x = 0, int y = 0, double len = 0) :x(x), y(y), len(len) {}
	bool friend operator <(const node&a, const node &b)
	{
		return a.len < b.len;
	}
}dis[100000];

int father[205];
//int rankk[2005];
double site[205][3];
int ans;

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		//rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	//int i = x;
	//while (father[i] != far)
	//{
		//int temp = father[i];
		//father[i] = far;
		//i = temp;
	//}
	return far;
}

void unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	//if (rankk[x] < rankk[y])
		father[x] = y;
	//else
	//{
	//	father[y] = x;
	//	if (rankk[x] == rankk[y])
		//	rankk[x] ++;
	//}
}

int main(void)
{
	int casee = 1;
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
			if (find(dis[i].x) != find(dis[i].y))
			{
				unoin(dis[i].x, dis[i].y);
				if (find(1) == find(2))
				{
					maxx = dis[i].len;
					break;
				}
			}
		}
		printf("Scenario #%d\n", casee++);
		printf("Frog Distance = %.3lf\n\n", maxx);
	}
	return 0;
} 