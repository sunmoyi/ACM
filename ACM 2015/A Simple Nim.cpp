#include<cstdio>
#include<cstring>

using namespace std;

long long T, num,  sum, a;

int main(void)
{
	scanf("%lld", &T);
	while (T--)
	{
		sum = 0;
		scanf("%lld", &num);
		for (long long i = 1; i <= num; i++)
		{
			scanf("%lld", &a);
			sum ^= a;
		}
		if (sum)
			printf("First player wins.\n");
		else
			printf("Second player wins.\n");
	}
	return 0;
}