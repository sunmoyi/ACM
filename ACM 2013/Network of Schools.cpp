#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int n;
int map[maxn][maxn];
int low[maxn];
int dfn[maxn];
int stack[maxn], head;
int instack[maxn];
int belong[maxn];
int in[maxn];
int out[maxn];
int index, cnt;

void init()
{
	int i, j;
	int temp;
	memset(map, 0, sizeof(map));
	memset(dfn, -1, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	index = cnt = 1;
	head = 0;
	for (i = 1; i <= n; i++)
	{
		while (scanf("%d", &temp) && temp)
		{
			map[i][temp] = 1;
		}
	}
}

void tarjan(int x)
{
	int i, a;
	low[x] = dfn[x] = index++;
	stack[++head] = x;
	instack[x] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!map[x][i])
			continue;
		if (dfn[i] == -1)
		{
			tarjan(i);
			low[x] = min(low[x], low[i]);
		}
		else if (instack[i])
			low[x] = min(low[x], dfn[i]);
	}

	if (low[x] == dfn[x])
	{
		int temp;
		while (true)
		{
			temp = stack[head--];
			belong[temp] = cnt;
			instack[temp] = 0;
			if (temp == x)
				break;
		}
		cnt++;
	}
}

void solve()
{
	int i, j;
	int t1, t2;
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (int i = 1; i <= n; i++)
			if (dfn[i] == -1)
				tarjan(i);

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (map[i][j] && belong[i] != belong[j])
				{
					out[belong[i]]++;
					in[belong[j]]++;
				}
			}
		}

		t1 = t2 = 0;
		for (i = 1; i < cnt; i++)
		{
			if (in[i] == 0)
				t1++;
			if (out[i] == 0)
				t2++;
		}
		if (cnt == 2)
			printf("1\n0\n");
		else
			printf("%d\n%d\n", t1, max(t1, t2));
	}
}

int main(void)
{
	solve();
	return 0;
}