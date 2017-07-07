#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double sum[100000009 / 50];

int main(void)
{
	sum[0] = 0;
	for (int i = 1; i <= 100000003 / 50; i++)
	{
		double a = 0;
		for (int j = (i - 1) * 50 + 1; j <= i * 50; j++)
			a += (1.0 / j);
		sum[i] = sum[i - 1] + a;

	}
	int ans;
	while (scanf("%d", &ans) != EOF)
	{
		int s = 0;
		while (ans--)
		{
			int a = 0;
			scanf("%d", &a);
			int b = a / 50;
			double fin = sum[b];
			for (int i = b * 50 + 1; i <= a; i++)
				fin += 1.0 / i;
			printf("Case %d: %.10lf\n", ++s, fin);
		}
	}
	return 0;
}