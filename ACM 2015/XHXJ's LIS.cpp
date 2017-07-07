#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N = 20;

ll dp[N][10][1 << 10][11];
int hashh[1 << 10];
int nextt[1 << 10][10];
int bit[N], K;

int go(int mask, int number) 
{
	int pos = -1;
	for (int i = number; i <= 9; i++)
	{
		if (mask & (1 << i))
		{
			pos = i;
			break;//Ѱ�����λ��1
		}
	}
	if (pos == -1)
		mask |= 1 << number;//���û�ҵ���ônumber�����������һ��
	else
	{
		mask ^= 1 << pos;
		mask |= 1 << number;
	}
	return mask;
}

void init() 
{
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i< (1 << 10); i++) 
	{
		hashh[i] = 0;
		for (int j = 0; j < 10; j++)
			if (i&(1 << j))
				hashh[i]++;//�����õ���NlogN������������еļ�¼��ʽ
	}
	for (int i = 0; i < 1 << 10; i++)
		for (int j = 0; j < 10; j++)
			nextt[i][j] = go(i, j);//���i�������׺j֮���LIS
}

ll dfs(int pos, int number, int mask, bool isZero, bool flag)
{
	if (pos == 0)
		return hashh[mask] == K;//ע�������mask��������������õ��� ����������������hash֮�����
	if (flag && ~dp[pos][number][mask][K])
		return dp[pos][number][mask][K];
	ll ans = 0;
	int u = flag ? 9 : bit[pos];
	for (int d = 0; d <= u; d++)
	{
		if (isZero && d == 0)
			ans += dfs(pos - 1, d, 0, 1, flag || d < u);
		else 
			ans += dfs(pos - 1, d, nextt[mask][d], 0, flag || d < u);
	}
	if (flag)
		dp[pos][number][mask][K] = ans;
	return ans;
}

ll solve(ll n)
{
	int len = 0;
	while (n) 
	{
		bit[++len] = n % 10;
		n /= 10;
	}
	return dfs(len, 0, 0, 1, 0);
}

int main() 
{
	init();
	ll L, R;
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) 
	{
		cin >> L >> R >> K;
		cout << "Case #" << cas << ": " << solve(R) - solve(L - 1) << endl;
	}
	return 0;
}