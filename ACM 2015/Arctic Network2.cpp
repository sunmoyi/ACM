#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxn 1010

using namespace std;

struct node{
	int from;
	int to;
	double len;
	node(int from = 0, int to = 0, double len = 0) :from(from), to(to), len(len) {}
	friend bool operator < (const node &a, const node &b)
	{
		return a.len < b.len;
	}
}edge[maxn * maxn];

struct Point {
	double x;
	double y;
}point[maxn];

int n, m;
int father[maxn];
//int rankk[maxn];
int ss;
double Q[maxn];

double dis(Point a, Point b)
{ 
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void init(int x)
{
	for (int i = 0; i <= x; i++)
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
	//	int temp = father[i];
	//	father[i] = far;
	//	i = temp;
	//}
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	//if (rankk[x] < rankk[y])
		father[x] = y;
//	else
	//{
	//	father[y] = x;
	//	if (rankk[x] == rankk[y])
	//	{
	//		rankk[x]++;
	//	}
	//}
	return true;
}

double kruskal(void)
{
	int kk = 0;
	for (int i = 1; i < ss; i++)
	{
		if (unoin(edge[i].from, edge[i].to))
		{
			Q[kk++] = edge[i].len;
		}
	}
	return Q[m - n - 1];
}

int main(void)
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d %d", &n, &m);
			init(m + 1);
			ss = 1;
			for (int i = 1; i <= m; i++)
				scanf("%lf %lf", &point[i].x, &point[i].y);

			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					edge[ss].from = i;
					edge[ss].to = j;
					edge[ss++].len = dis(point[i], point[j]);
				}
			}

			sort(edge + 1, edge + ss);
			double ans = kruskal();
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}