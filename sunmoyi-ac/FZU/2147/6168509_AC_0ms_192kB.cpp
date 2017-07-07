#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
long long A, B;

int main(void)
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%lld %lld", &A, &B);
		int ans = 0;
		while (A > B)
		{
			if (A % 2 == 0)
			{
				A /= 2;
				A++;
			}
			else
				A /= 2;
			ans++;
		}
		printf("Case %d: ", i);
		printf("%d\n", ans);
	}
	return 0;
}