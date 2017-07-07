#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define esp 1e-8

using namespace std;

double fun(double x)
{
	return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x;
}

double cai(double x, double y)
{
	return 6.0*pow(x, 7.0) + 8.0*pow(x, 6.0) + 7.0*pow(x, 3.0) + 5.0*pow(x, 2.0) - y*x;
}

int main(void)
{
	int t;
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			double y;
			scanf_s("%lf", &y);
			if (fun(100) > y)
			{
				double l = 0, u = 100;
				while (l + esp < u)
				{
					double mid = (l + u) / 2;
					if (fun(mid) > y)
						u = mid - 1e-7;
					else
						l = mid + 1e-7;
				}
				double m = (l + u) / 2;
				printf("%.4lf\n", cai(m, y));
			}
			else
			{
				printf("%.4lf\n", cai(100, y));
			}
		}
	}
}