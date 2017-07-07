#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300010

using namespace std;

char str[maxn];

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		long long ans = 0;
		int len = strlen(str);
		for (int i = len - 1; i >= 0; i--)
		{
			if ((str[i] - '0') % 4 == 0)
				ans++;
			if (i == 0)
				break;
			int temp = (str[i - 1] - '0') * 10 + str[i] - '0';
			if (temp % 4 == 0)
				ans += i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
//A F G L