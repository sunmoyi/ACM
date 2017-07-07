#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5010

using namespace std;

int len[maxn], bad[maxn];
int map[1100][maxn];

int main (void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		n += 8;
		for (int i = 1; i <= m; i++)
			scanf("%d", &len[m + 1 - i]);
		//printf("1\n");
		for (int i = 0; i <= m; i++)
			bad[i] = (len[i] - len[i - 1]) * (len[i] - len[i - 1]);
		//printf("2\n");
		memset(map, 0x42, sizeof(map));
		for (int i = 0; i <= m; i++)
			map[0][i] = 0;
		for(int i = 1; i <= n; i++)
		{
			for (int j = 3 * i; j <= m - (n - i) * 2; j++)
			{
				map[i][j] = min(map[i][j - 1] , map[i - 1][j - 2] + bad[j]);
			}
		}
		printf("%d\n", map[n][m]);
	}
	return 0;
}