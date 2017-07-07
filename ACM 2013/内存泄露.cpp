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
	
	cout << prime.size() << prime.capacity() << endl;
	cout << "1111111\n";
	
	cout << "22222222222\n";
	cout << prime.size()<< "   " << prime.capacity() << endl;
	
	//prime.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; i++)
		prime.push_back(i);
	cout << "3333333\n";
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
	cout << prime.size() << " " << prime.capacity() << endl;
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
	int n;
	int *a = &n;
	printf("%x\n", a);
	get_prime();
	
	while (scanf_s("%d", &n) && n) 
	{
		int ans = -1, len = prime.size(), cnt;
		for (int i = 0; i < len; ++i) 
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
		if (n != 1)
			ans = 1;
		if (n < 0) 
		{
			while (ans % 2 == 0)
				ans = ans / 2;
			printf("%d\n", ans);
		}
		else 
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
