#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<string>
#include<iostream>
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	string name;
	int dead, cost;
}a[50];

struct kode {
	int time, score, pre, now;
}dp[1 << 15];

int main (void)
{
	int t, i, j, s, n, end;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].name >> a[i].dead >> a[i].cost;
		end = 1 << n;
		for (s = 1; s < end; s++)
		{
			dp[s].score = INF;
			for (i = n - 1; i >= 0; i--)
			{
				int tem = 1 << i;
				if (s & tem)
				{
					int past = s - tem;
					int st = dp[past].time + a[i].cost - a[i].dead;
					if (st < 0)
						st = 0;
					if (st + dp[past].score < dp[s].score)
					{
						dp[s].score = st + dp[past].score;
						dp[s].now = i;
						dp[s].pre = past;
						dp[s].time = dp[past].time + a[i].cost;
					}
				}
			}
		}
		stack<int>S;
		int tem = end - 1;
		cout << dp[tem].score << endl;
		while (tem)
		{
			S.push(dp[tem].now);
			tem = dp[tem].pre;
		}
		while (!S.empty())
		{
			cout << a[S.top()].name << endl;
			S.pop();
		}
	}
	return 0;
}