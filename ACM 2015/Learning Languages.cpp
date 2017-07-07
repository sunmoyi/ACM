#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int father[maxn];
bool flag[maxn];

int find(int x)
{
	while (father[x] != x)
		x = father[x];
	return x;
}

void unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		father[x] = y;
}

void init(int m)
{
	for (int i = 0; i <= m; i++)
		father[i] = i;
	memset(flag, false, sizeof(flag));
}

int main(void)
{
	int n, m, ans;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		ans = 0;
		init(m);
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);
			if (!k)
				ans++;
			else
			{
				int temp;
				int kk;
				scanf("%d", &kk);
				flag[kk] = true;
				for (int j = 1; j < k; j++)
				{
					scanf("%d", &temp);
					flag[temp] = true;
					unoin(kk, temp);
				}
			}
		}
		int temp = 0;
		for (int i = 1; i <= m; i++)
		{
			if (flag[i] && father[i] == i)
				temp++;
		}
		if (temp > 1)
			ans += temp - 1;
		printf("%d\n", ans);
	}
	return 0;
}