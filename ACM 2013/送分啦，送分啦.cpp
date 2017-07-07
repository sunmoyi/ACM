#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

double y;

double fun(double x)
{
	return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}

int main(void)
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%lf", &y);
			if ((y - 6.0) < 0|| (y - 807020306) > 0)
			{
				printf("No solution!\n");
				continue;
			}
			double left = 0, right = 100;
			double mid;
			for (int i = 1; (right - left) > 1e-6; i++)
			{
				mid = (left + right) / 2;
				if (fun(mid) > y)
					right = mid;
				else
					left = mid;
			}
			printf("%.4f\n", mid);
		}
	}
	return 0;
}