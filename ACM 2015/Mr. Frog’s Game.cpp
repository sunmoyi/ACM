#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 35

using namespace std;

int map[maxn][maxn];
int T;
int n, m;

int main(void)
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &map[i][j]);

		bool check = false;
		for (int i = 1; i <= m; i++)
			for (int j = i + 1; j <= m; j++)
				if (map[1][i] == map[1][j] || map[n][i] == map[n][j])
					check = true;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (map[i][1] == map[j][1] || map[i][m] == map[j][m])
					check = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < m; j++)
				if (map[i][j] == map[i][j + 1])
					check = true;
		for (int i = 1; i < n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j] == map[i + 1][j])
					check = true;

		if (check)
			printf("Case #%d: Yes\n", t);
		else
			printf("Case #%d: No\n", t);
	}
	return 0;
}