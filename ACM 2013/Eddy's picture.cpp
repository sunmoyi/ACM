#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	double x;
	double y;
}a[105];
struct node2{
	int from;
	int to;
	double len;
}b[100005];
int father[105];
int rankk[105];
int num;
int l = 1;

void init(int x)
{
	for (int i = 1; i <= x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	int i = x;
	while (father[i] != far)
	{
		int temp = father[i];
		father[i] = far;
		i = temp;
	}
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] == rankk[y])
			rankk[x] ++;
	}
	return true;
}

double juli(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double krustral()
{
	double lenn = 0;
	for (int i = 1; i < l; i++)
	{
		if (unoin(b[i].from, b[i].to))
			lenn += b[i].len;
	}
	return lenn;
}

bool cmp(node2 a, node2 b)
{
	return a.len < b.len;
}

int main(void)
{

	while (scanf("%d", &num) != EOF)
	{
		l = 1;
		init(104);
		for (int i = 1; i <= num; i++)
		{
			scanf("%lf %lf", &a[i].x, &a[i].y);
		}
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (i != j)
				{
					b[l].from = i;
					b[l].to = j;
					b[l].len = juli(a[i], a[j]);
					l++;
				}
			}
		}
		sort(b + 1, b + l, cmp);
		double lenn = krustral();
		printf("%.2lf\n", lenn);
	}
	return 0;
}