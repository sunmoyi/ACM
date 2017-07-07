#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 220000

using namespace std;

int c[maxn];
typedef vector<int> vector_int;
vector<vector_int>G(maxn / 2);
int lowbit[maxn];
bool hasapple[maxn];
int start[maxn];
int endd[maxn];
int ncount = 0;

void dfs(int v)
{
	start[v] = ++ncount;
	for (int i = 0; i < G[v].size(); i++)
		dfs(G[v][i]);
	endd[v] = ++ncount;
}

int query(int p)
{
	int nsum = 0;
	while (p > 0)
	{
		nsum += c[p];
		p -= lowbit[p];
	}
	return nsum;
}

void modify(int p, int val)
{
	while (p <= ncount)
	{
		c[p] += val;
		p += lowbit[p];
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int x, y;
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
	}
	ncount = 0;
	dfs(1);
	for (int i = 1; i <= ncount; i++)
		lowbit[i] = i & (-i);
	for (i = 1; i <= n; i++)
		hasapple[i] = 1;

	//树状数组要处理的原始数组下标范围 1 -- nCount
	int m;
	for (i = 1; i <= ncount; i++)
		c[i] = i - (i - lowbit[i]);
	//c[i] = sum[i] - sum[i - lowbit[i]];

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		char cmd[10];
		int a;
		scanf("%s%d", cmd, &a);
		if (cmd[0] == 'C')
		{
			if (hasapple[a])
			{
				modify(start[a], -1);
				modify(endd[a], -1);
				hasapple[a] = 0;
			}
			else
			{
				modify(start[a], 1);
				modify(endd[a], 1);
				hasapple[a] = 1;
			}
		}
		else
		{
			int t1 = query(endd[a]);
			int t2 = query(start[a] - 1);
			printf("%d\n", (t1 - t2) / 2);
		}
	}
	return 0;
}