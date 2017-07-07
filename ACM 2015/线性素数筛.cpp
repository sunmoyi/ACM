#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define maxn 1e7

using namespace std;

int main(void)
{
	int n; 
	cin >> n;
	vector<int>prime;
	vector<bool>isprime(n + 1);
	for (int i = 1; i <= n; i++)
		isprime[i] = true;

	for (int i = 2; i <= n; i++)
	{
		if (isprime[i])
			prime.push_back(i);
		for (int j = 0; j < prime.size(); j++)
		{
			if (i * prime[j] <= n)
				isprime[i * prime[j]] = false;
			else
				break;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 0; i < prime.size(); i++)
		cout << prime[i] << ' ';
	cout << endl;
	return 0;
}