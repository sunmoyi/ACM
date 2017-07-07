#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 310

using namespace std;

long long l[maxn], c[maxn];
map<long long, long long>mp;
int n;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		mp.clear();
		for (int i = 1; i <= n; i++)
			scanf("%lld", &l[i]);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &c[i]);
		mp.clear();
		mp[0] = 0;
		map<long long, long long>::iterator it;
		for (int i = 1; i <= n; i++)
		{
			for (it = mp.begin(); it != mp.end(); it++)
			{
				long long tt = it->first;
				long long temp = gcd(tt, l[i]);
				if (mp.count(temp))
					mp[temp] = min(mp[temp], it->second + c[i]);
				else
					mp[temp] = it->second + c[i];
			}
		}
		if (!mp[1])
			printf("-1\n");
		else
			printf("%lld\n", mp[1]);
	}
	return 0;
}