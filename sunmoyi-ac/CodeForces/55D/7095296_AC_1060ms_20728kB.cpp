#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 2520

using namespace std;

long long dp[21][mod][50];
int digit[21];
int indx[mod + 5];

void init()
{
	int num = 0;
	for (int i = 1; i <= mod; i++)
		if (mod % i == 0)
			indx[i] = num++;
	memset(dp, -1, sizeof(dp));
}

long long gcd(long long a, long long b) 
{
	return b == 0 ? a : gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b)*b;
}

long long dfs(int pos, int presum, int prelcm, bool edge)
{
	if (pos == -1)    
		return presum % prelcm == 0;
	if (!edge && dp[pos][presum][indx[prelcm]] != -1)
		return dp[pos][presum][indx[prelcm]];
	int ed = edge ? digit[pos] : 9;
	long long ans = 0;
	for (int i = 0; i <= ed; i++)
	{
		int nowlcm = prelcm;
		int nowsum = (presum * 10 + i) % mod;
		if (i)
			nowlcm = lcm(nowlcm, i);
		ans += dfs(pos - 1, nowsum, nowlcm, edge && i == ed);
	}
	if (!edge)
		dp[pos][presum][indx[prelcm]] = ans;
	return ans;
}

long long cal(long long x)
{
	memset(digit, 0, sizeof(digit));
	int pos = 0;
	while (x)
	{
		digit[pos++] = x % 10;
		x /= 10;
	}
	return dfs(pos - 1, 0, 1, 1);
}

int main(void)
{
	init();
	int T;
	long long a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", cal(b) - cal(a - 1));
	}
	return 0;
}