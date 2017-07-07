#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
long long ans;
long long a;

int main (void)
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &a);
		ans = (a - 1) * (a + 2) / 2;
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}