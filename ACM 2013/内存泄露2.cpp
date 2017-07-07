#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100005;

vector<int> prime;
int vis[N];

void get_prime() 
{
	prime.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < N; ++i) 
	{
		int t = N / i;
		for (int j = 2; j <= t; ++j)
			vis[i*j] = 1;
	}
	for (int i = 2; i < N; ++i) 
	{
		if (!vis[i])
			prime.push_back(i);
	}
}

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() 
{
	get_prime();
	int n;
	while (scanf_s("%d", &n), n)
	{
		int ans = -1, len = prime.size(), cnt;
		for (int i = 0; i < len && prime[i] * prime[i] <= n; ++i)
		{
			if (n%prime[i] == 0) 
			{
				cnt = 0;
				while (n%prime[i] == 0)
				{
					n /= prime[i];
					cnt++;
				}
				if (ans == -1)
					ans = cnt;
				else
					ans = gcd(ans, cnt);
			}
		}
		if (ans == -1)
			ans = 1;
		if (n < 0)
		{
			while (ans % 2 == 0)
			{
				ans = ans / 2;
			}
			printf("%d\n", ans);
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
