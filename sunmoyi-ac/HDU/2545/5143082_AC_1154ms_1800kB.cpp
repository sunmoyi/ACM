#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[100005];

void init(int x)
{
	for (int i = 1; i <= x; i++)
	{
		father[i] = i;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];
	return far;
}

int findstep(int x)
{
	int far = x;
	int step = 0;
	while (far != father[far])
	{
		step++;
		far = father[far];
	}
	return step;
}

void unite(int x, int y)
{
	//x = find(x);
	//y = find(y);
	father[y] = x;
}

int main(void)
{
	int num, astart, bstart, anum;
	while (scanf("%d %d", &num, &anum) != EOF && (num + anum))
	{
		init(num);
		for (int i = 1; i < num; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			unite(a, b);
		}
		for (int i = 1; i <= anum; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a = findstep(a);
			b = findstep(b);
			if (a <= b)
				printf("lxh\n");
			else
				printf("pfz\n");
		}
	}
	return 0;
}