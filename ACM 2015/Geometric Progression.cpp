#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 200010

using namespace std;

map<long long, long long>s1, s2;

int main(void)
{
	long long n, k, ans, x;
	scanf("%lld %lld", &n, &k);
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		if (x % k == 0)
		{
			long long t1 = s2[x / k];
			ans += t1;
			long long t2 = s1[x / k];
			s2[x] += t2;
		}
		s1[x]++;
	}
	printf("%lld\n", ans);
	return 0;
}