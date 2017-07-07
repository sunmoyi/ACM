#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	long long a, b, c, d, e;
	int num;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			d = c % a;
			e = c % b;
			if (d > e)
				printf("Xiangsanzi!\n");
			else if (d < e)
				printf("Sempr!\n");
			else
				printf("Both!\n");
		}
	}
	return 0;
}