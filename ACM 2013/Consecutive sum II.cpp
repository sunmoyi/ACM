#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num;
long long a;

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%lld", &a);
			printf("%lld %lld\n", a * a * a, (a + 1) * (a + 1) * (a + 1));
		}
	}
	return 0;
}