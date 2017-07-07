#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			long long y, n;
			scanf("%lld %lld", &y, &n);
			for (int i = 1; i <= n; )
			{
				if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
					i++;
				y++;
			}
			printf("%lld\n", y - 1);
		}
	}
	return 0;
}