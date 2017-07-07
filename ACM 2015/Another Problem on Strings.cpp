#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char s[maxn];
long long pre[maxn];
int id[maxn];

int main(void)
{
	int k;
	scanf("%d", &k);
	scanf("%s", s);
	
	int len = strlen(s);
	int cnt = 0;
	for (int i = 0; i <= len - 1; i++)
		if (s[i] == '1')
			id[++cnt] = i;
	id[0] = -1;
	id[cnt + 1] = len;
	for (int i = 1; i <= cnt + 1; i++)
		pre[i] = id[i] - id[i - 1] - 1;

	if (cnt < k)
	{
		printf("0\n");
	}
	else if (k >= 1)
	{
		long long ans = 0;
		for (int s = 1; s <= cnt - k + 1; s++)
		{
			int t = s + k - 1;
			ans += (pre[s] + 1) * (pre[t + 1] + 1);
		}
		printf("%lld\n", ans);
	}
	else if (k == 0)
	{
		long long ans = 0;
		for (int i = 1; i <= cnt + 1; i++)
			ans += (pre[i] * (pre[i] + 1)) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}