#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

string str;
int dp[maxn][maxn];
string fold[maxn][maxn];

int judge(int l, int r)
{
	for (int i = 1; i <= (r - l + 1) / 2; i++)
	{
		if ((r - l + 1) % i)
			continue;
		bool flag = true;
		for (int j = l; j + i <= r; j++)
		{
			if (str[j] != str[j + i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return i;
	}
	return false;
}

int DP(int l, int r)
{
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)
	{
		dp[l][r] = 1;
		fold[l][r] = str[l];
		return 1;
	}
	int k, re = INF;
	for (int i = l; i < r; i++)
	{
		int temp = DP(l, i) + DP(i + 1, r);
		if (temp < re)
		{
			k = i;
			re = temp;
		}
	}
	fold[l][r] = fold[l][k] + fold[k + 1][r];
	
	int len = judge(l, r);
	if (len)
	{
		char t[10];
		sprintf(t, "%d", (r - l + 1) / len);
		string newstr = t + string("(") + fold[l][l + len - 1] + string(")");
		if (newstr.size() < re)
		{
			re = newstr.size();
			fold[l][r] = newstr;
		}
	}
	dp[l][r] = re;
	return re;
}


int main(void)
{
	while (cin >> str)
	{
		int r = str.size() - 1;
		memset(dp, -1, sizeof(dp));
		DP(0, r);
		cout << fold[0][r] << endl;
	}
	return 0;
}