#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 20;
int s[1 << maxn];

int main(void)
{
	int d, n;
	while (scanf("%d %d", &d, &n) != EOF)
	{
		memset(s, 0, sizeof(s));
		int k, n = (1 << d) - 1;
		for (int i = 0; i <= n; i++)
		{
			k = 1;
			for (;;)
			{
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n)
					break;
			}
		}
		printf("%d\n", k / 2);
	}
	return 0;
}