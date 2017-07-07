#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <vector>  
#include <algorithm>  
#include <map>  
#include <string>  

using namespace std;

typedef long long LL;
const int Max = 110;
const LL INF = 0x3FFFFFFF;
int n;
int rem[Max][Max];
vector<int> dp;
vector<int> vec[Max];
int vis[Max];
int fin[Max];
int sad[Max];
int ans[Max][Max * 3];
int out[Max][Max * 3];
int be[Max][Max * 3];

int dfs(int t, int y, int cas)
{
	vis[t] = cas;
	if (fin[t] == y)
		return 0;
	if (fin[t] != -1)
		return -1;
	fin[t] = y;
	sad[t] = y;
	for (int i = 0; i<vec[t].size(); i++)
		if (dfs(vec[t][i], y ^ 1, cas) == -1)
			return -1;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			vec[i].clear();
		memset(vis, -1, sizeof vis);
		dp.clear();
		memset(rem, 0, sizeof rem);
		for (int i = 1; i <= n; i++)
		{
			int c;
			while (scanf("%d", &c) == 1 && c)
			{
				rem[i][c] = 1;
			}
			rem[i][i] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if ((!rem[i][j]) || (!rem[j][i]))
					vec[i].push_back(j);
		}
		bool flag = 0;
		int cas = 0;
		memset(sad, 0, sizeof sad);
		for (int i = 1; i <= n; i++)
		{
			memset(fin, -1, sizeof fin);
			if (vis[i] != -1)
				continue;
			if (dfs(i, 0, cas++) == -1)
			{
				flag = 1;
				break;
			}
			int t1 = 0, t2 = 0;
			for (int i = 1; i <= n; i++)
				if (fin[i] == 0)
					t1++;
				else if (fin[i] == 1)
					t2++;
			dp.push_back(t1 - t2);
		}
		if (flag)
		{
			puts("No solution");
			if (t>0)
				cout << endl;
			continue;
		}
		memset(ans, 0, sizeof ans);
		memset(be, 0, sizeof be);
		ans[0][100 + dp[0]] = 1;
		out[0][100 + dp[0]] = 0;
		ans[0][100 - dp[0]] = 1;
		out[0][100 - dp[0]] = 1;
		for (int i = 1; i<dp.size(); i++)
		{
			for (int j = 0; j <= 100 * 2; j++)
			{
				if (ans[i - 1][j])
				{
					ans[i][j + dp[i]] = 1;
					out[i][j + dp[i]] = 0;
					be[i][j + dp[i]] = j;
					ans[i][j - dp[i]] = 1;
					out[i][j - dp[i]] = 1;
					be[i][j - dp[i]] = j;
				}
			}
		}
		int m = dp.size();
		vector<int> ans0;
		vector<int> ans1;
		for (int i = 0; i <= 100; i++)
		{
			if (ans[m - 1][100 - i] == 1 || ans[m - 1][100 + i] == 1)
			{
				int num;
				if (ans[m - 1][100 - i] == 1)
					num = 100 - i;
				else
					num = 100 + i;
				for (int k = m - 1; k >= 0; k--)
				{
					for (int i = 1; i <= n; i++)
					{
						if (vis[i] == k&&sad[i] == out[k][num])
							ans0.push_back(i);
						if (vis[i] == k&&sad[i] == 1 - out[k][num])
							ans1.push_back(i);
					}
					num = be[k][num];
				}
				break;
			}
		}
		cout << ans0.size();
		for (int i = 0; i<ans0.size(); i++)
			cout << " " << ans0[i];
		cout << endl;
		cout << ans1.size();
		for (int i = 0; i<ans1.size(); i++)
			cout << " " << ans1[i];
		cout << endl;
		if (t>0)
			cout << endl;
	}
	return 0;
}