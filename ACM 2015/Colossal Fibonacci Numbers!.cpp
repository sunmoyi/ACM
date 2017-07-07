#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;
vector<int>fib[1010];

void init()
{
	for(int i = 2; i <= 1000; i++)
	{
		int mod = i;
		int a = 0, b = 1, c = (a + b) % mod;
		fib[i].push_back(a);
		fib[i].push_back(b);
		fib[i].push_back(c);
		while (!(b == 0 && c == 1))
		{
			a = b;
			b = c;
			c = (a + b) % mod;
			fib[i].push_back(c);
		}
		fib[i].pop_back();
		fib[i].pop_back();
	}
}

unsigned long long quick_mod(unsigned long long a, unsigned long long b, unsigned long long m)
{
	unsigned long long res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * (a % m)) % m;
			b--;
		}
		b >>= 1;
		a = ((a % m) * (a % m)) % m;
	}
	return res;
}

int main(void)
{
	unsigned long long a, b, n;
	int T;
	init();
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> n;
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		unsigned long long ans = quick_mod(a, b, fib[n].size());
		cout << fib[n][ans] << endl;
	}
	return 0;
}