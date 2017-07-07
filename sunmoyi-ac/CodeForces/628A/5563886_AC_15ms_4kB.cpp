#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		int sum2 = a * c;
		int sumwater = 2 * b + 1;
		int maxwater = 0;
		while (a >= 2)
		{
			maxwater += (a / 2) * sumwater;
			a = a - (a / 2);
		}
		printf("%d %d\n", maxwater, sum2);
	}
	return 0;
}