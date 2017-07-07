#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define Min(x, y)(x > y? x: y)
using namespace std;
const int INF = 0xfffffff;
const int maxn = 155;
struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn];
int cnt[maxn];
int n, m = 1;//n代表边数   m代表定点数；
vector<node>G[maxn];
char str[155][35];

int check(char strr[])
{
	bool flag = true;
	int i;
	for (i = 1; i < m; i++)
	{
		if (strcmp(strr, str[i]) == 0)
		{
			flag = false;
			break;
		}
	}
	if (!flag)
		return i;
	else
	{
		strcpy_s(str[m], 33, strr);
		return m++;
	}
}

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		cnt[i] = 0;
		G[i].clear();
		memset(str[i], 0, sizeof(str[i]));
	}
}

int Dijkstra(int s, int t)
{
	mindist[s] = 0;
	cnt[s]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		Q.push(G[s][i]);
		inqueue[vex] = true;
		cnt[vex]++;
		mindist[vex] = min(mindist[vex], G[s][i].len);
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int len = G[now.v][i].len;
			int vex = G[now.v][i].v;
			if (mindist[vex] > len + mindist[now.v])
			{
				mindist[vex] = len + mindist[now.v];
				if(!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == m)
					{
						return INF;
					}
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return mindist[t];
}

int main(void)
{
	char str1[35], str2[35], len, a, b, s, t;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		init();
		m = 1;
		getchar();
		scanf("%s %s", str1, str2);
		s = check(str1);
		t = check(str2);
		for (int i = 1; i <= n; i++)
		{
			getchar();
			scanf("%s %s %d", &str1, &str2, &len);
			a = check(str1);
			b = check(str2);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		int ans = Dijkstra(s, t);
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}