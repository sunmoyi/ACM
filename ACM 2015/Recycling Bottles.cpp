#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 10000010

using namespace std;

struct node {
	int x, y;
}pa, pb, p, temp;
double dis[3][maxn];
int n;

double dist(node a, node b)
{
	return sqrt((a.x - b.x)*1.0*(a.x - b.x) + (a.y - b.y)*1.0*(a.y - b.y));
}

int main(void)
{
	scanf("%d %d %d %d %d %d", &pa.x, &pa.y, &pb.x, &pb.y, &p.x, &p.y);
	
	dis[0][0] = dis[1][0] = dis[2][0] = 0;
	double tot = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &temp.x, &temp.y);
		dis[0][i] = dist(temp, pa);
		dis[1][i] = dist(temp, pb);
		dis[2][i] = dist(temp, p);
		tot += (dis[2][i] * 2);
	}

	double add1 = 1e18;
	int id = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[0][i] - dis[2][i] < add1)
		{
			add1 = dis[0][i] - dis[2][i];
			id = i;
		}
	}
	double add2 = dis[1][0] - dis[2][0];
	for(int i = 1; i <= n; i++)
	{
		if (i == id)
			continue;
		else if (dis[1][i] - dis[2][i] < add2)
			add2 = dis[1][i] - dis[2][i];
	}

	double plus = add1 + add2;

	add1 = 1e18;
	id = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[1][i] - dis[2][i] < add1)
		{
			add1 = dis[1][i] - dis[2][i];
			id = i;
		}
	}
	add2 = dis[0][0] - dis[2][0];
	for (int i = 0; i <= n; i++)
	{
		if (i == id)
			continue;
		else if (dis[0][i] - dis[2][i] < add2)
			add2 = dis[0][i] - dis[2][i];
		if (add1 + add2 < plus)
			plus = add1 + add2;
		
	}
	printf("%.12lf\n", tot + plus);
	return 0;
}