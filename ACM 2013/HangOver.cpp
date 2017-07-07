#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double sum[100000];

int main(void)
{
	for (int i = 2; i < 100000; i++)
	{
		sum[i - 1] = sum[i - 2] + 1 / (double)i;
	}
	double lengh;
	while (scanf("%lf", &lengh) != EOF && lengh - 0.00 > 1e-5)
	{
		int i;
		for (i = 1;; i++)
			if (sum[i - 1] < lengh && sum[i] >= lengh)
				break;
		printf("%d card(s)\n", i);
	}
	return 0;
}