/*◊¢“‚—∞’“*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long s[4];

int main(void)
{
	int a, b, n, m, j, k, l;
	int ans;
	while(scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d %d", &a, &b, &n, &m);
			s[0] = a;
			s[1] = b;
			j = 2, k = 1, l = 0;
			int ans = 1;
			for (int i = 1; i <= m; i++)
				ans *= 10;
			for (int i = 2; i <= n; i++)
			{
				s[j] = (s[k] + s[l]) % ans;
				j++, k++,l++;
				if (j == 3)
					j = 0;
				if (k == 3)
					k = 0;
				if (l == 3)
					l = 0;
			}
			printf("%d\n", s[n % 3]);
		}
	}
	return 0;
}