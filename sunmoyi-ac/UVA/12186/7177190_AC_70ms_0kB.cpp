#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1000010

using namespace std;

vector<int>sons[maxn];

int T, N;

int dp(int u)
{
	if (sons[u].empty())
		return 1;
	int k = sons[u].size();
	vector<int>d;
	for (int i = 0; i < k; i++)
		d.push_back(dp(sons[u][i]));
	sort(d.begin(), d.end());
	int x = (k * T - 1) / 100 + 1;
	int ans = 0;
	for (int i = 0; i < x; i++)
		ans += d[i];
	return ans;
}

int main(void)
{
	while (scanf("%d %d", &N, &T) != EOF && (N + T))
	{
		for (int i = 0; i <= N; i++)
			sons[i].clear();

		for (int i = 1; i <= N; i++)
		{
			int x;
			scanf("%d", &x);
			sons[x].push_back(i);
		}
		printf("%d\n", dp(0));
	}
	return 0;
}