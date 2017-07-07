#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[1050];
int rankk[1050];
int a[1050];
int t;
int n, m;
int s, ss;

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
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			init(1050);
			scanf_s("%d %d", &n, &m);
			for (int i = 1; i <= m; i++)
			{
				scanf_s("%d %d", &s, &ss);
				unoin(s, ss);
			}

			for (int i = 1; i <= n; i++)
				a[find(i)]++;

			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (a[i])
					ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}