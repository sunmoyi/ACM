#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[1005];
int rankk[1005];
int a[1005];
int n, m;

void init(int x)
{
	for (int i = 1; i < x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
		a[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (father[far] != far)
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

void unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] == rankk[y])
			rankk[x]++;
	}
}

int main(void)
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		scanf_s("%d", &m);
		init(1005);
		int s, ss;
		for (int i = 1; i <= m; i++)
		{
			scanf_s("%d %d", &s, &ss);
			unoin(s, ss);
		}

		for (int i = 1; i <= n; i++)
		{
			a[find(i)]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (a[i])
				ans++;
		printf("%d\n", ans - 1);
	}
	return 0;
}