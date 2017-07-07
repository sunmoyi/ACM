#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 666

using namespace std;

int father[maxn];
int rankk[maxn];
int a[maxn][2];
vector<int>b[maxn][2];
bool used[maxn];
int dp[maxn][maxn / 2];
int pre[maxn][maxn / 2];

int find(int x)
{
	if (father[x] == -1)return x;
	int temp = find(father[x]);
	rankk[x] += rankk[father[x]];
	rankk[x] %= 2;
	return father[x] = temp;
}

int main(void)
{
	int n, p1, p2;
	while (scanf_s("%d %d %d", &n, &p1, &p2) != EOF && (n + p1 + p2))
	{
		memset(father, -1, sizeof(father));
		memset(rankk, 0, sizeof(rankk));
		int u, v;
		char str[10];
		while (n--)
		{
			scanf_s("%d%d", &u, &v);
			scanf_s(" %s", str, 5);
			//printf("%s", str);
			int temp;
			if (str[0] == 'y')//相同
				temp = 0;
			else temp = 1;//相反
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
		memset(used,false,sizeof(used));
        int cnt=1;
		for (int i = 1; i <= p1 + p2; i++)
		{
			if (!used[i])
			{
				int tmp = find(i);
				for (int j = i; j <= p1 + p2; j++)
				{
					if (find(j) == tmp)
					{
						used[j] = true;
						b[cnt][rankk[j]].push_back(j);
						a[cnt][rankk[j]]++;
					}
				}
				cnt++;
			}
		}
		//printf("1111\n");
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i<cnt; i++)
		{
			for (int j = p1; j >= 0; j--)
			{
				if (j - a[i][0] >= 0 && dp[i - 1][j - a[i][0]])
				{
					dp[i][j] += dp[i - 1][j - a[i][0]];
					pre[i][j] = j - a[i][0];
				}

				if (j - a[i][1] >= 0 && dp[i - 1][j - a[i][1]])
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

			for (int i = cnt - 1; i >= 1; i--)
			{
				int temp = t - pre[i][t];
				if (temp == a[i][0])
				{
					for (int j = 0; j < a[i][0]; j++)
						ans.push_back(b[i][0][j]);
				}
				else
				{
					for (int j = 0; j < a[i][1]; j++)
						ans.push_back(b[i][1][j]);
				}
				t = pre[i][t];
			}

			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				printf("%d\n", ans[i]);
			printf("end\n");
		}
	}
	return 0;
}