#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#define INF 0x3f3f3f3f
#define maxn 50
using namespace std;

int n, m;
double rate;
char str[maxn], str1[maxn], str2[maxn];
double dist[maxn][maxn];
map<string, int>mp;
int i, j, k;

void floyed(void)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dist[i][j] < dist[i][k] * dist[k][j])
					dist[i][j] = dist[i][k] * dist[k][j];
			}
		}
	}
	return;
}

int main(void)
{
	int icase = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		getchar();
		mp.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			mp[str] = i;
			dist[i][i] = 1;
		}
		scanf("%d", &m);
		getchar();
		for (int i = 1; i <= m; i++)
		{
			scanf("%s %lf %s", str1, &rate, str2);
			dist[mp[str1]][mp[str2]] = rate;
		}

		floyed();

		int flag = false;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i][i] > 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			printf("Case %d: Yes\n", icase++);
		else
			printf("Case %d: No\n", icase++);
	}
	return 0;
}