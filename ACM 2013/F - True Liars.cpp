#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#define maxn 666

using namespace std;

int father[maxn];
int rankk[maxn];
int a[maxn][2];//a代表的是数目 
vector<int>b[maxn][2];//b代表的是a的中具体的人
bool used[maxn];
int dp[maxn][maxn / 2];
int pre[maxn][maxn / 2];

int find(int x)
{
	if (father[x] == -1)
		return x;
	int temp = find(father[x]);
	rankk[x] += rankk[father[x]];
	rankk[x] %= 2;
	return father[x] = temp;
}

int main(void)
{
	int n, p1, p2;
	while (scanf("%d %d %d", &n, &p1, &p2) != EOF && (n + p1 + p2))
	{
		memset(father, -1, sizeof(father));
		memset(rankk, 0, sizeof(rankk));
		int u, v;
		char str[10];
		while (n--)
		{
			scanf("%d %d %s", &u, &v, str);
			int temp;
			if (str[0] == 'y')
				temp = 0;
			else
				temp = 1;
			int t1 = find(u), t2 = find(v);
			if (t1 != t2)
			{
				father[t1] = t2;
				rankk[t1] = (rankk[v] - rankk[u] + temp + 2) % 2;
			}
		}
		for (int i = 0; i < maxn; i++)
		{
			b[i][0].clear();
			b[i][1].clear();
			a[i][0] = 0;
			a[i][1] = 0;
		}
		memset(used, 0, sizeof(used));
		int cnt = 1;
		for (int i = 1; i <= p1 + p2; i++)
		{
			if (!used[i])
			{
				int temp = find(i);
				for (int j = i; j <= p1 + p2; j++)
				{
					if (find(j) == temp)
					{
						used[j] = true;
						b[cnt][rankk[j]].push_back(j);
						a[cnt][rankk[j]]++;
					}
				}
				cnt++;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i < cnt; i++)
		{
			for (int j = p1; j >= 0; j--)
			{
				if (j - a[i][0] >= 0 && dp[i - 1][j - a[i][0]])
				{
					dp[i][j] += dp[i - 1][j - a[i][0]];
					pre[i][j] = j - a[i][0];
				}
				if (j - a[i][1] >= 0 && dp[j - 1][j - a[i][1]])
				{
					dp[i][j] += dp[i - 1][j - a[i][1]];
					pre[i][j] = j - a[i][1];
				}
			}
		}
		if (dp[cnt - 1][p1] != 1)
			printf("no\n");
		else
		{
			vector<int>ans;
			ans.clear();
			int t = p1;

			for (int i = cnt - 1; i >= 1; i++)
			{
				int temp = t - pre[i][t];
				if (temp == a[i][0])
				{
					for (int j = 0; j < a[i][0]; j++)
						ans.push_back(b[i][0][j]);
				}
				else
				{
					for (int j = 0; j<a[i][1]; j++)
						ans.push_back(b[i][1][j]);
				}
				t = pre[i][t];
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i<ans.size(); i++)
				printf("%d\n", ans[i]);
			printf("end\n");
		}
	}
	return 0;
}