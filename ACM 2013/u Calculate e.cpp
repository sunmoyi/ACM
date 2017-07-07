#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	double sum = 1;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	int k = 1;
	for (int i = 1; i <= 9; i++)
	{
		k *= i;
		sum += 1.0 / k;
		if (i == 1)
			printf("%d %d\n", i, (int)sum);
		else if (i == 2)
			printf("%d %.1lf\n", i, sum);
		else
			printf("%d %.9lf\n", i, sum);
	}
	return 0;
}