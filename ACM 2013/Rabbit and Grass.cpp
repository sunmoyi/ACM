#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int t, a, sum;
	while (scanf_s("%d", &t) != EOF && t)
	{
		sum = 0;
		for (int i = 1; i <= t; i++)
		{
			scanf_s("%d", &a);
			sum ^= a;
		}
		if (sum == 0)
			printf("Grass Win!\n");
		else
			printf("Rabbit Win!\n");
	}
	return 0;
}