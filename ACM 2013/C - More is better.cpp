#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[10000005];
int rankk[10000005];
int a[10000005];
int maxxx;

void init(int x)
{
	for (int i = 1; i <= x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
		a[i] = 0;
	}
	maxxx = 1;
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

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rankk[x] > rankk[y])
		father[y] = x;
	else
	{
		father[x] = y;
		if (rankk[x] == rankk[y])
			rankk[x]++;
	}
}

int main(void)
{
	int num, b, c;
	while (scanf_s("%d", &num) != EOF)
	{
		init(1000001);
		while (num--)
		{
			scanf_s("%d %d", &b, &c);
			if (b > maxxx)
				maxxx = b;
			if (c > maxxx)
				maxxx = c;
			unite(b, c);
		}
		for (int i = 1; i <= maxxx; i++)
			a[find(i)]++;
		int maxx = a[1];
		for (int i = 2; i <= maxxx; i++)
			if (a[i] > maxx)
				maxx = a[i];
		printf("%d\n", maxx);
	}
	return 0;
}